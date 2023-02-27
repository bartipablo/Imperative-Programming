#ifndef MY_HEADER_H3
#define MY_HEADER_H3

#define SIZE 40

void get_solution_to_system_of_linear_equations(double A[][SIZE], double x[], const double b[], const int n);

double gauss(double A[][SIZE], double b[], double x[], const int n, const double eps);

#endif