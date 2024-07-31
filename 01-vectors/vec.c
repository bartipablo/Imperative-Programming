#include <stdio.h>
#define N 100


int range(double array[], double start, double stop, double step) {
    int i = 0;
    while ( ((start<stop) && (step>0)) || ((start>stop) && (step<0)) ) {
        array[i] = start;
        i++;
        start += step;
    }
    return i;
}


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


void multiply_by_scalar(double v[], int n, double scalar) {
    for (int i = 0; i < n; i++) {
        v[i] *= scalar;
    }
}


void add(double v1[], const double v2[], int n) {
    for (int i = 0; i < n; i++) {
        v1[i] += v2[i];
    }
}


double dot_product(const double v1[], const double v2[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += (v1[i] * v2[i]);
    }
    return result;
}


void read_vector(double v[], int n) {
    double value_read;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &value_read);
        v[i] = value_read;
    }
}


void print_vector(const double v[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%.2f ", v[i]);
	}
	printf("\n");
}
