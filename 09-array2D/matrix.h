#ifndef MATRIX_H
#define MATRIX_H

#define BUF_SIZE  1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_mat(int rows, int cols, double *t);

void print_mat(int rows, int cols, double *t);

double get(int cols, int row, int col, const double *A);

void set(int cols, int row, int col, double *A, double value);

void prod_mat(int rowsA, int colsA, int colsB, double *A, double *B, double *AB);

int read_dbl_lines_v1(double *ptr_tab[], double *series_table);

void write_dbl_line_v1(double *ptr_tab[], int n);

int read_char_lines(char *tab[]);

void write_char_line(char *tab[], int n);

void delete_lines(char *tab[], int line_count);


#endif