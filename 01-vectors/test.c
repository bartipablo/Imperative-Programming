#include "E:\biblioteki\c++\minunit\minunit\minunit.h"
#include "vec.h"

void assert_double_array(double t1[], double t2[], int size) {
    for (int i = 0; i < size; i++) {
        mu_assert_double_eq(t1[i], t2[i]);
    }
}

// int range(double array[], double start, double stop, double step) TESTS---------------------------------------------
MU_TEST(range_test1) {
    int size = 10;
    double start = 0;
    double stop = 10;
    double step = 1;
    double expected_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double result_array[10];
    range(result_array, start, stop, step);
    assert_double_array(expected_array, result_array, size);
}

MU_TEST(range_test2) {
    int size = 12;
    double start = 0;
    double stop = 10;
    double step = 0.9;
    double expected_array[] = {0, 0.9, 1.8, 2.7, 3.6, 4.5, 5.4, 6.3, 7.2, 8.1,
                               9.0, 9.9};
    double result_array[12];
    range(result_array, start, stop, step);
    assert_double_array(expected_array, result_array, size);
}

MU_TEST(range_test3) {
    int size = 12;
    double start = 10;
    double stop = 0;
    double step = -0.9;
    double expected_array[] = {10, 9.1, 8.2, 7.3, 6.4, 5.5, 4.6, 3.7, 2.8, 1.9,
                               1.0, 0.1};
    double result_array[12];
    range(result_array, start, stop, step);
    assert_double_array(expected_array, result_array, size);
}

MU_TEST(range_test4) {
    int size = 1;
    double start = 1;
    double stop = 1.2;
    double step = 0.3;
    double expected_array[] = {1};
    double result_array[1];
    range(result_array, start, stop, step);
    assert_double_array(expected_array, result_array, size);
}
//----------------------------------------------------------------------------------------------------------------------


//void lin_space(double v[], double start, double stop, int n)----------------------------------------------------------
MU_TEST(linspace_test1) {
    double start = 10;
    double stop = 100;
    int n = 1;
    int size = 1;
    double expected_array[] = {10};
    double result_array[1];
    lin_space(result_array, start, stop, n);
    assert_double_array(expected_array, result_array, size);
}

MU_TEST(linspace_test2) {
    double start = 10;
    double stop = 100;
    int n = 10;
    int size = 10;
    double expected_array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    double result_array[10];
    lin_space(result_array, start, stop, n);
    assert_double_array(expected_array, result_array, size);
}

MU_TEST(linspace_test3) {
    double start = 0;
    double stop = 10;
    int n = 9;
    int size = 9;
    double expected_array[] = {0, 1.25, 2.50, 3.75, 5.00, 6.25, 7.5, 8.75, 10};
    double result_array[10];
    lin_space(result_array, start, stop, n);
    assert_double_array(expected_array, result_array, size);
}
//----------------------------------------------------------------------------------------------------------------------


//void multiply_by_scalar(double v[], int n, double scalar)-------------------------------------------------------------
MU_TEST(muliply_by_scalar_test1) {
    int n = 10;
    double scalar = 2.5;
    double expected_array[] = {2.5, 5.0, 7.5, 10, 12.5, 15, 17.5, 20, 22.5, 25};
    double result_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    multiply_by_scalar(result_array, n, scalar);
    assert_double_array(expected_array, result_array, n);
}

MU_TEST(muliply_by_scalar_test2) {
    int n = 1;
    double scalar = 7.2;
    double expected_array[] = {14.4};
    double result_array[] = {2};
    multiply_by_scalar(result_array, n, scalar);
    assert_double_array(expected_array, result_array, n);
}
//----------------------------------------------------------------------------------------------------------------------


//void add(double v1[], const double v2[], int n)-----------------------------------------------------------------------
MU_TEST(add_test1) {
    int n = 10;
    double v1[] = {1, 2, 3.7, 4.1, 5, 6, 7, 8, 9, 10};
    double v2[] = {3, 5, 6.4, 3, 2, 1, -5, -20, -2.2, 100};
    double expected_array[] = {4, 7, 10.1, 7.1, 7, 7, 2, -12, 6.8, 110};
    add(v1, v2, n);
    assert_double_array(expected_array, v1, n);
}
//----------------------------------------------------------------------------------------------------------------------


//double dot_product(const double v1[], const double v2[], int n)-------------------------------------------------------
MU_TEST(dot_product_test1) {
    int n = 10;
    double v1[] = {1, 2, 3.7, 4.1, 5, 6, 7, 8, 9, 10};
    double v2[] = {3, 5, 6.4, 3, 2, 1, -5, -20, -2.2, 100};
    double expected_value = 1*3 + 2*5 + 3.7*6.4 + 4.1*3 + 5*2 + 6*1 + 7*(-5) + 8*(-20) + 9*(-2.2) + 10*100;
    double result_value = dot_product(v1, v2, n);
    mu_assert_double_eq(expected_value, result_value);
}
//----------------------------------------------------------------------------------------------------------------------

MU_TEST_SUITE(range_test_suite) {
    MU_RUN_TEST(range_test1);
    MU_RUN_TEST(range_test2);
    MU_RUN_TEST(range_test3);
    MU_RUN_TEST(range_test4);
}

MU_TEST_SUITE(linspace_test_suite) {
    MU_RUN_TEST(linspace_test1);
    MU_RUN_TEST(linspace_test2);
    MU_RUN_TEST(linspace_test3);
}

MU_TEST_SUITE(multiply_by_scalar_test_suite) {
    MU_RUN_TEST(muliply_by_scalar_test1);
    MU_RUN_TEST(muliply_by_scalar_test2);
}

MU_TEST_SUITE(add_test_suite) {
    MU_RUN_TEST(add_test1);
}

MU_TEST_SUITE(dot_product_test_suite) {
    MU_RUN_TEST(dot_product_test1);
}

int main(void) {
    MU_RUN_SUITE(range_test_suite);
    MU_RUN_SUITE(linspace_test_suite);
    MU_RUN_SUITE(multiply_by_scalar_test_suite);
    MU_RUN_SUITE(add_test_suite);
    MU_RUN_SUITE(dot_product_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}