#ifndef PERM_H
#define PERM_H

void swap(int *a, int *b);

// Draws one integer from the interval [a,b] using the rand() function and the % operator
int rand_from_interval(int a, int b);

// A random permutation of the set of numbers {0, 1, 2,..., n-1}
void rand_permutation(int n, int tab[]);

//bubble-sort, Returns the number of outer loop iterations (counted from 1) after which the array was sorted,
int bubble_sort(int n, int tab[]);

#endif