#ifndef MY_HEADER_H0
#define MY_HEADER_H0

#define SIZE 40

void swap(double *a, double *b);

void swap_rows(double A[][SIZE], int n, int m, int cols_no);

int change_order_of_rows(double A[][SIZE], double b[], const int row_index, const int rows_no, const int cols_no, const double eps);

void read_vector(double x[], int n);

void print_vector(double x[], int n);

void read_mat(double A[][SIZE], int m, int n);

void print_mat(double A[][SIZE], int m, int n);

double determinant(double matrix[SIZE][SIZE], int n);

#endif