#include "E:\biblioteki\c++\minunit\minunit\minunit.h"
#include "matrixproduct.h"
#include "gausssimplified.h"
#include "gauss.h"
#include "inversematrix.h"

// compilation (in Windows PowerShell):
// gcc gauss.c gausssimplified.c matrixproduct.c generalfunction.c test.c inversematrix.c -o tests -lm


#define SIZE 40

void assert_matrix(double expected_matrix[][SIZE], double result_matrix[][SIZE], int row_no, int col_no) {
    for (int i = 0; i < row_no; i++) {
        for (int j = 0; j < col_no; j++) {
            mu_assert_double_eq(expected_matrix[i][j], result_matrix[i][j]);
        }
    }
}

void asser_vector(double expected_vector[], double result_vector[], int n) {
    for (int i = 0; i < n; i++) {
        mu_assert_double_eq(expected_vector[i], result_vector[i]);
    }
}

void round_matrix(double A[][SIZE], int row_no, int col_no) {
    for (int i = 0; i < row_no; i++) {
        for (int j = 0; j < col_no; j++) {
            A[i][j] = round(A[i][j] * 1000) / 1000;
        }
    }
}

// matrix product TESTS-------------------------------------------------------------------------------------------------
MU_TEST(matrix_product_test1) {
    int A_row_no = 2;
    int A_col_no = 3;
    int B_col_no = 2;
    double A[SIZE][SIZE] = {{1, 2, 3}, {10, 20, 30}};
    double B[SIZE][SIZE] = { {11, 23}, {1, 1.5}, {-2, 0} };
    double AB_expected[SIZE][SIZE] = {{7.0000, 26.0000}, {70.0000, 260.0000}};
    double AB_result[SIZE][SIZE] = {0};
    mat_product(A, B, AB_result, A_row_no, A_col_no, B_col_no);
    assert_matrix(AB_expected, AB_result, 2, 2);
}

MU_TEST(matrix_product_test2) {
    int A_row_no = 1;
    int A_col_no = 1;
    int B_col_no = 1;
    double A[SIZE][SIZE] = {{ 3 }};
    double B[SIZE][SIZE] = { {7} };
    double AB_expected[SIZE][SIZE] = {{21} };
    double AB_result[SIZE][SIZE] = {0};
    mat_product(A, B, AB_result, A_row_no, A_col_no, B_col_no);
    assert_matrix(AB_expected, AB_result,  1, 1);
}

MU_TEST(matrix_product_test3) {
    int A_row_no = 1;
    int A_col_no = 3;
    int B_col_no = 2;
    double A[SIZE][SIZE] = {{-6, -3, -1}};
    double B[SIZE][SIZE] = {{-3, 6}, {-2, -6}, {6, -1}};
    double AB_expected[SIZE][SIZE] = {{18, -17}};
    double AB_result[SIZE][SIZE] = {0};
    mat_product(A, B, AB_result, A_row_no, A_col_no, B_col_no);
    assert_matrix(AB_expected, AB_result,  1, 2);
}

MU_TEST(matrix_product_test4) {
    int A_row_no = 3;
    int A_col_no = 3;
    int B_col_no = 3;
    double A[SIZE][SIZE] = {{9, 2, 7}, {5, 8, -1}, {0, 0, -3}};
    double B[SIZE][SIZE] = {{-1, 2, 13}, {-3, 0, 7}, {-4, -1, 12}};
    double AB_expected[SIZE][SIZE] = {{-43, 11, 215}, {-25, 11, 109}, {12, 3, -36}};
    double AB_result[SIZE][SIZE] = {0};
    mat_product(A, B, AB_result, A_row_no, A_col_no, B_col_no);
    assert_matrix(AB_expected, AB_result,  3, 3);
}
// matrix product TESTS-------------------------------------------------------------------------------------------------

// gauss simplified TESTS-----------------------------------------------------------------------------------------------
MU_TEST(gauss_simplified_test1) {
    double A[SIZE][SIZE] = {{1, 3}, {7, 1}};
    double A_expected[SIZE][SIZE] = {{1, 3}, {0, -20}};
    double det = gauss_simplified(A, 2);
    double det_expected = -20;
    mu_assert_double_eq(det_expected, det);
    assert_matrix(A_expected, A, 2, 2);
}

MU_TEST(gauss_simplified_test2) {
    double A[SIZE][SIZE] = {{1, -3, 2}, {1, 1, -2}, {2, -1, 1}};
    double A_expected[SIZE][SIZE] = {{1, -3, 2}, {0, 4, -4}, {0, 0, 2}};
    double det = gauss_simplified(A, 3);
    double det_expected = 8;
    mu_assert_double_eq(det_expected, det);
    assert_matrix(A_expected, A, 3, 3);
}

MU_TEST(gauss_simplified_test3) {
    double A[SIZE][SIZE] = {{1}};
    double A_expected[SIZE][SIZE]  = {{1}};
    double det = gauss_simplified(A, 1);
    double det_expected = 1;
    mu_assert_double_eq(det_expected, det);
    assert_matrix(A_expected, A, 1, 1);
}

MU_TEST(gauss_simplified_test4) {
    double A[SIZE][SIZE] = {{1, 2, 1}, {1, 0, 2}, {1, 1, 1}};
    double det = gauss_simplified(A, 1);
    double det_expected = NAN;
    mu_assert_double_eq(det_expected, det);
}
// gauss simplified TESTS-----------------------------------------------------------------------------------------------

// gauss TESTS ---------------------------------------------------------------------------------------------------------
MU_TEST(gauss_test1) {
    double A[SIZE][SIZE] = {{1, -1, 2, -1}, {2, -2, 3, -3}, {1, 1, 1, 0}, {1, -1, 4, 3}};
    double b[SIZE] = {-8, -20, -2, 4};
    double x[SIZE] = {0};
    double A_expected[SIZE][SIZE]  = {{1, -1, 2, -1}, {0, 2, -1, 1}, {0, 0, -1, -1}, {0, 0, 0, 2}};
    double b_expected[SIZE] = {-8, 6, -4, 4};
    double x_expected[SIZE] = {-7, 3, 2, 2};
    double det = gauss(A, b, x, 4, 0.005);
    double det_expected = 4;
    mu_assert_double_eq(det_expected, det);
    mu_assert_double_eq(det, det_expected);
    assert_matrix(A_expected, A, 4, 4);
    asser_vector(b_expected, b, 4);
    asser_vector(x_expected, x, 4);
}

MU_TEST(gauss_test2) {
    double A[SIZE][SIZE] = {{1}};
    double b[SIZE] = {9};
    double x[SIZE] = {0};
    double A_expected[SIZE][SIZE]  = {{1}};
    double b_expected[SIZE] = {9};
    double x_expected[SIZE] = {9};
    double det = gauss(A, b, x, 1, 0.005);
    double det_expected = 1;
    mu_assert_double_eq(det_expected, det);
    mu_assert_double_eq(det, det_expected);
    assert_matrix(A_expected, A, 1, 1);
    asser_vector(b_expected, b, 1);
    asser_vector(x_expected, x, 1);
}

MU_TEST(gauss_test3) {
    double A[SIZE][SIZE] = {{1, -1, 2, -1}, {2, -2, 3, -3}, {1, 1, 0, 0}, {1, -1, 4, 3}};
    double b[SIZE] = {-8, -20, -2, 4};
    double x[SIZE] = {0};
    double A_expected[SIZE][SIZE]  = {{1, -1, 2, -1}, {0, 2, -2, 1}, {0, 0, -1, -1}, {0, 0, 0, 2}};
    double b_expected[SIZE] = {-8, 6, -4, 4};
    double x_expected[SIZE] = {-6, 4, 2, 2};
    double det = gauss(A, b, x, 4, 0.005);
    double det_expected = 4;
    mu_assert_double_eq(det_expected, det);
    mu_assert_double_eq(det, det_expected);
    assert_matrix(A_expected, A, 4, 4);
    asser_vector(b_expected, b, 4);
    asser_vector(x_expected, x, 4);
}
// gauss TESTS ---------------------------------------------------------------------------------------------------------

// inverse matrix TESTS ------------------------------------------------------------------------------------------------
MU_TEST(inverse_matrix_test1) {
    double A[SIZE][SIZE] = {{1, 2, -1}, {2, 1, 0}, {-1, 1, 2}};
    double B[SIZE][SIZE] = {{0}};
    double B_expected[SIZE][SIZE] = {{-0.2222, 0.5556, -0.1111}, {0.4444, -0.1111, 0.2222}, {-0.3333, 0.3333, 0.3333}};
    double det_expected = -9;
    double det = matrix_inv(A, B, 3, 0.005);
    round_matrix(B, 3, 3);
    round_matrix(B_expected, 3, 3);
    assert_matrix(B_expected, B, 3, 3);
    mu_assert_double_eq(det_expected, det);
}

// inverse matrix TESTS ------------------------------------------------------------------------------------------------

MU_TEST_SUITE(matrix_product_test_suite) {
    MU_RUN_TEST(matrix_product_test1);
    MU_RUN_TEST(matrix_product_test2);
    MU_RUN_TEST(matrix_product_test3);
    MU_RUN_TEST(matrix_product_test4);
}

MU_TEST_SUITE(gauss_simplified_test_suite) {
    MU_RUN_TEST(gauss_simplified_test1);
    MU_RUN_TEST(gauss_simplified_test2);
    MU_RUN_TEST(gauss_simplified_test3);
    MU_RUN_TEST(gauss_simplified_test4);
}

MU_TEST_SUITE(gauss_test_suite) {
    MU_RUN_TEST(gauss_test1);
    MU_RUN_TEST(gauss_test2);
    MU_RUN_TEST(gauss_test3);
}

MU_TEST_SUITE(invers_matrix_test_suite) {
    MU_RUN_TEST(inverse_matrix_test1);
}

int main(void) {
    MU_RUN_SUITE(matrix_product_test_suite);
    MU_RUN_SUITE(gauss_simplified_test_suite);
    MU_RUN_SUITE(gauss_test_suite);
    MU_RUN_SUITE(invers_matrix_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}