#include "generalfunction.h"
#include <stddef.h>

// 5.4
// Returns the determinant; B contains the inverse of A (if det(A) != 0)
// If max A[i][i] < eps, function returns 0.
void set_unit_matrix(double A[][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2*n; j++) {
            A[i][j] = (i == j-n) ? 1.0 : 0.0;
        }
    }
}

double matrix_inv(double A[][SIZE], double B[][SIZE], int n, double eps) {
    double det = determinant(A, n);
    set_unit_matrix(A, n);
    for (int i = 0; i < n; i++) { // Gaussian method
        if (A[i][i] == 0) { //Swapping rows
            int rows_changed = change_order_of_rows(A, NULL, i, n, 2*n, eps);
            if (!rows_changed) {
                return 0;
            }
        }
        double pivot = A[i][i];
        for (int j = i; j < 2*n; j++) {
            A[i][j] /= pivot;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor = A[j][i];
                for (int k = i; k < 2*n; k++) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2*n; j++) {
            A[i][j] /= A[i][i];
            B[i][j-n] = A[i][j];
        }
    }
    return det;
}