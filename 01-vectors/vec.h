#ifndef VEC_H
#define VEC_H

int range(double array[], double start, double stop, double step);

void lin_space(double v[], double start, double stop, int n);

void multiply_by_scalar(double v[], int n, double scalar);

void add(double v1[], const double v2[], int n);

double dot_product(const double v1[], const double v2[], int n);

void print_vector(const double v[], int n);

void read_vector(double v[], int n);

#endif