#include "E:\biblioteki\c++\minunit\minunit\minunit.h"
#include "perm.h"

void assert_int_array(int t1[], int t2[], int size) {
    for (int i = 0; i < size; i++) {
        mu_assert_int_eq(t1[i], t2[i]);
    }
}

//bubble sort tests----------------------------------------------------------------------------------------------------
MU_TEST(bubble_sort_test1) {
    int size = 10;
    int input_array[] = {5, 57, 86, 2, 67, 90, 70, 39, 51, 71};
    int expected_array[] = {2, 5, 39, 51, 57, 67, 70, 71, 86, 90};
    bubble_sort(size, input_array);
    assert_int_array(expected_array, input_array, size);
}

MU_TEST(bubble_sort_test2) {
    int size = 10;
    int input_array[] = {2, 0, -6, 10, -5, -3, 3, 10, -9, -10};
    int expected_array[] = {-10, -9, -6, -5, -3, 0, 2, 3, 10, 10};
    bubble_sort(size, input_array);
    assert_int_array(expected_array, input_array, size);
}

MU_TEST(bubble_sort_test3) {
    int size = 1;
    int input_array[] = {1};
    int expected_array[] = {1};
    bubble_sort(size, input_array);
    assert_int_array(expected_array, input_array, size);
}

MU_TEST(bubble_sort_test4) {
    int size = 8;
    int array[] =  {0, 1, 2, 3, 7, 4, 5, 6};
    int expected_value = 2;
    int result = bubble_sort(size, array);
    mu_assert_int_eq(expected_value, result);
}

MU_TEST(bubble_sort_test5) {
    int size = 8;
    int array[] =  { 1, 2, 3, 7, 4, 5, 6, 0};
    int expected_value = 8;
    int result = bubble_sort(size, array);
    mu_assert_int_eq(expected_value, result);
}

MU_TEST(bubble_sort_test6) {
    int size = 8;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int expected_value = 1;
    int result = bubble_sort(size, array);
    mu_assert_int_eq(expected_value, result);
}


//bubble sort tests----------------------------------------------------------------------------------------------------

MU_TEST_SUITE(bubble_sort_test_suite) {
    MU_RUN_TEST(bubble_sort_test1);
    MU_RUN_TEST(bubble_sort_test2);
    MU_RUN_TEST(bubble_sort_test3);
    MU_RUN_TEST(bubble_sort_test4);
    MU_RUN_TEST(bubble_sort_test5);
    MU_RUN_TEST(bubble_sort_test6);
}

int main(void) {
    MU_RUN_SUITE(bubble_sort_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}