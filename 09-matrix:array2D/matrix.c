#include "matrix.h"


void read_mat(int rows, int cols, double *t) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double value;
            scanf ("%lf", &value);
            set(cols, i, j, t, value);
        }
    }
}


void print_mat(int rows, int cols, double *t) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", get(cols, i, j, t));
        }
        printf("\n");
    }
}


double get(int cols, int row, int col, const double *A) {
    return A[cols * row + col];
}


void set(int cols, int row, int col, double *A, double value) {
    A[cols * row + col] = value;
}


void prod_mat(int rowsA, int colsA, int colsB, double *A, double *B, double *AB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            double sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += get(colsA, i, k, A) * get(colsB, k, j, B);
            }
            set(colsB, i, j, AB, sum);
        }
    }
}


int read_dbl_lines_v1(double *ptr_tab[], double *series_table) {
    char line[BUF_SIZE];
    int read_val = 0;
    int read_line = 0;

    while (fgets(line, BUF_SIZE, stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *ptr = line;
        if (*ptr == '\0') continue;

        ptr_tab[read_line] = &series_table[read_val];

        while (*ptr != '\0') {

            double value;
            int chars_read;

            if (sscanf(ptr, "%lf%n", &value, &chars_read) == 1) {
                series_table[read_val] = value;
                ptr += chars_read;
                read_val++;
            } else {
                break;
            }
        }

        read_line++;
    }
    ptr_tab[read_line] = &series_table[read_val];

    return read_line;
}


void write_dbl_line_v1(double *ptr_tab[], int n) {
    double *tmp_ptr = ptr_tab[n];
    double *end_ptr = ptr_tab[n + 1];

    while (tmp_ptr != end_ptr) {
        printf("%lf ", *tmp_ptr);
        tmp_ptr++;
    }
    printf("\n");
}


int read_char_lines(char *tab[]) {
    int read_lines = 0;
    char line[BUF_SIZE];

    while (fgets(line, BUF_SIZE, stdin) != NULL) {
        char *line_ptr = line;
        if (*line_ptr == '\0' || *line_ptr == '\n') continue;

        size_t length = strlen(line_ptr);
        tab[read_lines] = malloc(length + 1);
        strcpy(tab[read_lines], line_ptr);
        read_lines++;
    }

    return read_lines;
}


void write_char_line(char *tab[], int n) {
    printf("%s", tab[n]);
}


void delete_lines(char *tab[], int line_count) {
    for (int i = 0; i < line_count; i++) {
        free(tab[i]);
    }
}


