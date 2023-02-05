#include <stdio.h>
#include "vec.h"

#define N 100

int main(void) {

    int to_do, len;
    double start, stop, step, scalar;
    double vector_1[N], vector_2[N];

    scanf("%d", &to_do);

    switch (to_do) {
        case 1: // lin-space
            scanf("%d %lf %lf", &len, &start, &stop);
            lin_space(vector_1, start, stop, len);
            print_vector(vector_1, len);
            break;
        case 2: // add
            scanf("%d", &len);
            read_vector(vector_1, len);
            read_vector(vector_2, len);
            add(vector_1, vector_2, len);
            print_vector(vector_1, len);
            break;
        case 3: // dot product
            scanf("%d", &len);
            read_vector(vector_1, len);
            read_vector(vector_2, len);
            printf("%.2f\n", dot_product(vector_1, vector_2, len));
            break;
        case 4: // multiply by scalar
            scanf("%d %lf", &len, &scalar);
            read_vector(vector_1, len);
            multiply_by_scalar(vector_1, len, scalar);
            print_vector(vector_1, len);
            break;
        case 5: // range
            scanf("%lf %lf %lf", &start, &stop, &step);
            int n = range(vector_1, start, stop, step);
            print_vector(vector_1, n);
            break;
        default:
            printf("Unknown operation %d", to_do);
            break;
    }
    return 0;
}