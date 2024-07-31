#define SIZE 40


void mat_product(double A[][SIZE], double B[][SIZE], double AB[][SIZE], int m, int p, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                AB[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
}