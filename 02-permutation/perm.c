#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100
#define TRUE 1
#define FALSE 0

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}


// Draws one integer from the interval [a,b] using the rand() function and the % operator
int rand_from_interval(int a, int b) {
    if (a > b) {
        return INT_MIN;
    }
    if (b - a > RAND_MAX) {
        return INT_MAX;
    }
    if (a == b) {
        return a;
    }
    int length = (b - a) + 1;
    return (rand() % length) + a;
}


// A random permutation of the set of numbers {0, 1, 2,..., n-1}
void rand_permutation(int n, int tab[]) {
    for (int i = 0; i < n; i++) {
        tab[i] = i;
    }
    int k, p;
    for (int i = 0; i < n-1; i++) {
        k = rand_from_interval(i,n-1);
        swap(&tab[i],&tab[k]);
    }
}


//bubble-sort, Returns the number of outer loop iterations (counted from 1) after which the array was sorted,
int bubble_sort(int n, int tab[]) {
    int number_of_iteration = 1;
    for (int i = 0; i < n-1; i++) {
        int was_sorted = TRUE;
        for (int j = 0; j < n-i-1; j++) {
            if (tab[j] > tab[j+1]) {
                swap(&tab[j],&tab[j+1]);
                was_sorted = FALSE;
            }
        }
        if (was_sorted) {
            break;
        } else {
            number_of_iteration++;
        }
    }
    return number_of_iteration;
}

