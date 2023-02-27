#ifndef MY_HEADER_H4
#define MY_HEADER_H4

#define SIZE 40

void set_unit_matrix(double A[][SIZE], int n);

double matrix_inv(double A[][SIZE], double B[][SIZE], int n, double eps);

#endif