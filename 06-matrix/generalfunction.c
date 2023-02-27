#include <stdio.h>
#include <math.h>

#define SIZE 40
#define OK 1
#define ERROR 0

//general function------------------------------------------------------------------------------------------------------
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swap_rows(double A[][SIZE], int n, int m, int cols_no) {
    for (int i = 0; i < cols_no; i++) {
        swap(&A[n][i], &A[m][i]);
    }
}

int change_order_of_rows(double A[][SIZE], double b[], const int row_index, const int rows_no, const int cols_no, const double eps) {
    double max_abs_value = 0;
    int row_index_with_max_abs;
    for (int i = row_index; i < rows_no; i++) {
        if (fabs(A[i][row_index]) > max_abs_value) {
            max_abs_value = fabs(A[i][row_index]);
            row_index_with_max_abs = i;
        }
    }
    if (max_abs_value < eps) {
        return ERROR;
    }
    swap_rows(A, row_index, row_index_with_max_abs, cols_no);
    if (b != NULL) {
        swap(&b[row_index_with_max_abs], &b[row_index]);
    }
    return OK;
}

void read_vector(double x[], int n) {
    for(int i = 0; i < n; ++i) {
        scanf("%lf", x++);
    }
}

void print_vector(double x[], int n) {
    for(int i = 0; i < n; ++i) {
        printf("%.4f ", x[i]);
    }
    printf("\n");
}

void read_mat(double A[][SIZE], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lf", &A[i][j]);
        }
    }
}

void print_mat(double A[][SIZE], int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%.4f ", A[i][j]);
        }
        printf("\n");
    }
}

double determinant(double matrix[SIZE][SIZE], int n) {
    double det = 0;
    double submatrix[SIZE][SIZE];
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    } else {
        for (int k = 0; k < n; k++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k) {
                        continue;
                    }
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += pow(-1, k) * matrix[0][k] * determinant(submatrix, n - 1);
        }
    }
    return det;
}
