#ifndef VEC_H
#define VEC_H

// generates the sequence by incrementing the start value
// using the step size until it reaches the stop value
// (stop value is not included)
int range(double array[], double start, double stop, double step);

// Returns n evenly spaced samples, calculated over the interval [start, stop].
// n >= 0
// for n = 0 return empty array
// for n = 1 return one-element array, with array[0] = start
void lin_space(double v[], double start, double stop, int n);

// multiply each element of v by the value of scalar
void multiply_by_scalar(double v[], int n, double scalar);

// add to each element v1[i] value of v2[i]
void add(double v1[], const double v2[], int n);

// calculate and return the dot product of v1 and v2
double dot_product(const double v1[], const double v2[], int n);

// read double vector of size n
void print_vector(const double v[], int n);

// print double vector of size n (with 2 significant figures)
void read_vector(double v[], int n);

#endif