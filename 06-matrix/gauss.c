#define SIZE 40
#include "generalfunction.h"


void get_solution_to_system_of_linear_equations(double A[][SIZE], double x[], const double b[], const int n) { // the input matrix must be in triangular form
    for (int i = n-1; i >= 0; i--) {
        double val = b[i];
        for (int j = n-1; j > i; j--) {
            val -= A[i][j] * x[j];
        }
        val /= A[i][i];
        x[i] = val;
    }
}

double gauss(double A[][SIZE], double b[], double x[], const int n, const double eps) {
    double det = 1;
    for (int i = 1; i < n; i++) { // Gaussian method
        if (A[i-1][i-1] == 0) { //Swapping rows
            int rows_changed = change_order_of_rows(A, b, i - 1, n, n, eps);
            if (!rows_changed) {
                return 0; // could not find row to replace
            }
            det *= -1;
        }
        for (int j = i; j < n; j++) {
            double val = (A[j][i-1] / A[i-1][i-1]);
            for (int k = 0; k < n; k++) {
                A[j][k] -= val * A[i-1][k];
            }
            b[j] -= val * b[i-1];
        }
    } //calculating the determinant
    for (int i = 0; i < n; i++) {
        det *= A[i][i];
    }
    get_solution_to_system_of_linear_equations(A, x, b, n);
    return det;
}
