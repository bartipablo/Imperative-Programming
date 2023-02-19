#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "perm.h"

#define N 100
#define TRUE 1
#define FALSE 0

int main(void) {
    int nr_testu, seed;
    int a, b, n;
    int tab[N];

    scanf("%d %d",&nr_testu, &seed);
    srand((unsigned)seed); // ustawienie ziarna generatora (dla powtarzalnosci wynikow)

    switch(nr_testu) {
        case 1:
            scanf("%d %d",&a, &b);
            for(int i = 0; i < 3; ++i) {
                printf("%d ", rand_from_interval(a, b));
            }
            printf("\n");
            break;
        case 2:
            scanf("%d", &n);
            rand_permutation(n, tab);
            for(int i = 0; i < n; ++i) printf("%d ",tab[i]);
            printf("\n");
            break;
        case 3:
            scanf("%d", &n);
            rand_permutation(n, tab);
            printf("%d\n", bubble_sort(n, tab));
            break;
        default:
            printf("NOTHING TO DO!\n");
            break;
    }
    return 0;
}