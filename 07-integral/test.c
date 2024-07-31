#include <math.h>

#include "../minunit.h"
#include "function.h"
#include "function-pointer.h"
#include "integral.h"

double round_double(double number) {
    return round(number * 100) / 100;
}


//integral 1D TESTS----------------------------------------------------------------------------------------------------
MU_TEST(integral_1D_test1) {
    double x1 = 0;
    double x2 = 10;
    int n = 1000;
    mu_assert_double_eq(49.95, round_double(int_left_rectangle(x1, x2, n, f_1d_1)));
    mu_assert_double_eq(50.05, round_double(int_right_rectangle(x1, x2, n, f_1d_1)));
    mu_assert_double_eq(50.00, round_double(int_mid_rectangle(x1, x2, n, f_1d_1)));
    mu_assert_double_eq(50.00, round_double(int_trapezoid(x1, x2, n, f_1d_1)));
}

MU_TEST(integral_1D_test2) {
    double x1 = 0;
    double x2 = 10;
    int n = 1000;
    mu_assert_double_eq(166.42, round_double(int_left_rectangle(x1, x2, n, f_1d_2)));
    mu_assert_double_eq(166.92, round_double(int_right_rectangle(x1, x2, n, f_1d_2)));
    mu_assert_double_eq(166.67, round_double(int_mid_rectangle(x1, x2, n, f_1d_2)));
    mu_assert_double_eq(166.67, round_double(int_trapezoid(x1, x2, n, f_1d_2)));
}

MU_TEST(integral_1D_test3) {
    double x1 = 0;
    double x2 = 10;
    int n = 1000;
    mu_assert_double_eq(2.40, round_double(int_left_rectangle(x1, x2, n, f_1d_3)));
    mu_assert_double_eq(2.39, round_double(int_right_rectangle(x1, x2, n, f_1d_3)));
    mu_assert_double_eq(2.40, round_double(int_mid_rectangle(x1, x2, n, f_1d_3)));
    mu_assert_double_eq(2.40, round_double(int_trapezoid(x1, x2, n, f_1d_3)));
}

MU_TEST(integral_1D_test4) {
    double x1 = 0;
    double x2 = 10;
    int n = 1000;
    mu_assert_double_eq(7.11, round_double(int_left_rectangle(x1, x2, n, f_1d_4)));
    mu_assert_double_eq(7.12, round_double(int_right_rectangle(x1, x2, n, f_1d_4)));
    mu_assert_double_eq(7.11, round_double(int_mid_rectangle(x1, x2, n, f_1d_4)));
    mu_assert_double_eq(7.11, round_double(int_trapezoid(x1, x2, n, f_1d_4)));
}
//integral 1D TESTS----------------------------------------------------------------------------------------------------

//integral 2D TESTS----------------------------------------------------------------------------------------------------
MU_TEST(integral_2D_test1) {
    double x1 = -2; double y1 = -2;
    double x2 = 2;  double y2 = 2;
    int n = 1000;
    mu_assert_double_eq(4.27, round_double(integral_2d(x1, x2, n, y1, y2, n, f_2d_1, f_2d_1_boundary)));
    mu_assert_double_eq(40.20, round_double(integral_2d(x1, x2, n, y1, y2, n, f_2d_2, f_2d_2_boundary)));
    mu_assert_double_eq(0.21, round_double(integral_2d(x1, x2, n, y1, y2, n, f_2d_3, f_2d_3_boundary)));
}
//integral 2D TESTS----------------------------------------------------------------------------------------------------

//integral 3D TESTS----------------------------------------------------------------------------------------------------
//double integral_3d(double x1, double x2, int nx, double y1, double y2, int ny, double z1, double z2, int nz, f_3d f)
MU_TEST(integral_3D_test1) {
    double x1 = 1; double y1 = 2; double z1 = 3;
    double x2 = 2; double y2 = 3; double z2 = 4;
    int n = 200;
    mu_assert_double_eq(26.48, round_double(integral_3d(x1, x2, n, y1, y2, n, z1, z2, n, f_3d_1)));
    mu_assert_double_eq(30.08, round_double(integral_3d(x1, x2, n, y1, y2, n, z1, z2, n, f_3d_2)));
}
//integral 3D TESTS----------------------------------------------------------------------------------------------------

MU_TEST_SUITE(integral_1D_test_suite) {
    MU_RUN_TEST(integral_1D_test1);
    MU_RUN_TEST(integral_1D_test2);
    MU_RUN_TEST(integral_1D_test3);
    MU_RUN_TEST(integral_1D_test4);
}

MU_TEST_SUITE(integral_2D_test_suite) {
    MU_RUN_TEST(integral_2D_test1);
}

MU_TEST_SUITE(integral_3D_test_suite) {
    MU_RUN_TEST(integral_3D_test1);
}

int main(void) {
    MU_RUN_SUITE(integral_1D_test_suite);
    MU_RUN_SUITE(integral_2D_test_suite);
    MU_RUN_SUITE(integral_3D_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
