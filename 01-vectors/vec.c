#include <stdio.h>
#define N 100

// generates the sequence by incrementing the start value
// using the step size until it reaches the stop value
// (stop value is not included)
int range(double array[], double start, double stop, double step) {
    int i = 0;
    while ( ((start<stop) && (step>0)) || ((start>stop) && (step<0)) ) {
        array[i] = start;
        i++;
        start += step;
    }
    return i;
}

// Returns n evenly spaced samples, calculated over the interval [start, stop].
// n >= 0
// for n = 0 return empty array
// for n = 1 return one-element array, with array[0] = start
void lin_space(double v[], double start, double stop, int n) {
    if (n == 1) {
        v[0] = start;
    } else if (n > 1) {
        double step = (stop - start) / (n - 1);
        for (int i = 0; i < n; i++) {
            v[i] = start;
            start += step;
        }
    }
}

// multiply each element of v by the value of scalar
void multiply_by_scalar(double v[], int n, double scalar) {
    for (int i = 0; i < n; i++) {
        v[i] *= scalar;
    }
}

// add to each element v1[i] value of v2[i]
void add(double v1[], const double v2[], int n) {
    for (int i = 0; i < n; i++) {
        v1[i] += v2[i];
    }
}

// calculate and return the dot product of v1 and v2
double dot_product(const double v1[], const double v2[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += (v1[i] * v2[i]);
    }
    return result;
}

// read double vector of size n
void read_vector(double v[], int n) {
    double value_read;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &value_read);
        v[i] = value_read;
    }
}

// print double vector of size n (with 2 significant figures)
void print_vector(const double v[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%.2f ", v[i]);
	}
	printf("\n");
}

