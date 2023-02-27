#ifndef MY_HEADER_H1
#define MY_HEADER_H1

#include "function-pointer.h"

double int_left_rectangle(double x1, double x2, int n, f_1d f);

double int_right_rectangle(double x1, double x2, int n, f_1d f);

double int_mid_rectangle(double x1, double x2, int n, f_1d f);

double int_trapezoid(double x1, double x2, int n, f_1d f);

double integral_2d(double x1, double x2, int nx, double y1, double y2, int ny, f_2d f, boundary_2d boundary);

// 6.3 ----------------------------------------------------------------------------------------------------------------
double integral_3d(double x1, double x2, int nx, double y1, double y2, int ny, double z1, double z2, int nz, f_3d f);

#endif