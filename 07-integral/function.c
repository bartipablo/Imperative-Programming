#include <math.h>

// functions-----------------------------------------------------------------------------------------------------------
double f_1d_1(double x) {
    return x;
}

double f_1d_2(double x){
    return (x*x) / 2;
}

double f_1d_3(double x){
    return 1 / (x+1);
}

double f_1d_4(double x){
    if (x+1>0) return log10(x+1);
    else return 0;
}

double f_2d_1(double x, double y){
    return x * (y*y);
}

double f_2d_2(double x, double y){
    return x*x + y*y;
}

double f_2d_3(double x, double y){
    return (1 / ((1-x*x-y*y)*(1-x*x-y*y)));
}

int f_2d_1_boundary(double x, double y) {
    return x*x + y*y <= 4 && x >= 0;
}

int f_2d_2_boundary(double x, double y){
    return x*x + x*y - 2*y <= 0 || x*x + x*y - 2*y >= 1;
}

int f_2d_3_boundary(double x, double y){
    return x*x + y*y <= x && x*x + y*y <= y;
}

double f_3d_1(double x, double y, double z){
    return x + 3*y + 5*z;
}

double f_3d_2(double x, double y, double z){
    return 8*sin(x) + 5*cos(y)*5*cos(y) + 2*z;
}
// functions-----------------------------------------------------------------------------------------------------------
