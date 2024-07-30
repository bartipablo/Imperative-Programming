#include <stdio.h>

#include "matrix.h"

#define TAB_SIZE  1000


int main(void) {
    int to_do;

    scanf ("%d", &to_do);

    double A[TAB_SIZE], B[TAB_SIZE], C[TAB_SIZE];
    int n, lines_counter, rowsA,colsA,rowsB,colsB;
    char *char_lines_table[TAB_SIZE];
    double series_table[TAB_SIZE];
    double *ptr_table[TAB_SIZE];

    switch (to_do) {
        case 1:
            scanf("%d %d",&rowsA,&colsA);
            read_mat(rowsA, colsA, A);
            scanf("%d %d",&rowsB,&colsB);
            read_mat(rowsB, colsB, B);
            prod_mat(rowsA,colsA,colsB,A,B,C);
            print_mat(rowsA,colsB,C);
            break;
        case 2:
            scanf("%d",&n);
            lines_counter = read_dbl_lines_v1(ptr_table, series_table);
            write_dbl_line_v1(ptr_table,n);
            break;
        case 3:
            scanf("%d", &n);
            lines_counter = read_char_lines(char_lines_table);
            write_char_line(char_lines_table,n);
            delete_lines(char_lines_table,lines_counter);
            break;
        default:
            printf("NOTHING TO DO FOR %d\n", to_do);
    }
    return 0;
}
