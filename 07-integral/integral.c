#include "function-pointer.h"

// 6.1 ----------------------------------------------------------------------------------------------------------------
double int_left_rectangle(double x1, double x2, int n, f_1d f) {
    double length = (x2 - x1)/n;
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += f(x1) * length;
        x1 += length;
    }
    return result;
}

double int_right_rectangle(double x1, double x2, int n, f_1d f) {
    double length = (x2 - x1)/n ;
    double result = 0;
    for (int i = 0; i < n; i++) {
        x1 += length;
        result += f(x1) * length;
    }
    return result;
}

double int_mid_rectangle(double x1, double x2, int n, f_1d f) {
    double length = (x2 - x1)/n;
    double result = 0;
    x1 += (length/2);
    for (int i = 0; i < n; i++) {
        result += f(x1) * length;
        x1 += length;
    }
    return result;
}

double int_trapezoid(double x1, double x2, int n, f_1d f) {
    double length = (x2 - x1)/n; // trapezoid height
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += 0.5 * (f(x1) + f(x1+length)) * length; //pole trapezu
        x1 += length ;
    }
    return result;
}
// 6.1 ----------------------------------------------------------------------------------------------------------------


// 6.2 ----------------------------------------------------------------------------------------------------------------
double integral_2d(double x1, double x2, int nx, double y1, double y2, int ny, f_2d f, boundary_2d boundary) {
    double result = 0;
    double length_x = (x2 - x1)/nx;
    double length_y = (y2 - y1)/ny;
    double x_temp;

    for (int i = 0; i < ny; i++) {
        x_temp = x1;
        for (int j = 0; j < nx; j++) {
            if (boundary(x_temp,y1)) {
                result += f(x_temp,y1) * length_x * length_y;
            }
            x_temp += length_x;
        }
        y1 += length_y;
    }
    return result;
}
// 6.2 ----------------------------------------------------------------------------------------------------------------

// 6.3 ----------------------------------------------------------------------------------------------------------------
double integral_3d(double x1, double x2, int nx, double y1, double y2, int ny, double z1, double z2, int nz, f_3d f) {
    double result = 0;
    double length_x = (x2 - x1)/nx;
    double length_y = (y2 - y1)/ny;
    double length_z = (z2 - z1)/nz;
    double x_temp, y_temp;

    for (int i = 0; i < nz; i++) {
        y_temp = y1;
        for (int j = 0; j < ny; j++) {
            x_temp = x1;
            for (int k = 0; k < nx; k++) {
                result += f(x_temp, y_temp,z1) * length_x * length_y * length_z;
                x_temp += length_x;
            }
            y_temp += length_y;
        }
    z1 += length_z;
    }
    return result;
}
// 6.3 ----------------------------------------------------------------------------------------------------------------




