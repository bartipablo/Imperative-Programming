#include <math.h>
#define SIZE 40


double gauss_simplified(double A[][SIZE], int n) {
    for (int i = 1; i < n; i++) {
        if (A[i-1][i-1] == 0) {
            return NAN;
        }
        for (int j = 0; j < i; j++) {
            double val = A[i][j] / A[j][j];
            for (int k = 0; k < n; k++) {
                A[i][k] -= (val * A[j][k]);
            }
        }
    }
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= A[i][i];
    }
    return result;
}