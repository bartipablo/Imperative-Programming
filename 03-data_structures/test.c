#include "../minunit.h"
#include "data_structures.h"
#include <math.h>

#define STACK_SIZE 10

#define OK 0
#define EMPTY -1
#define FULL -2
#define OVERFLOW1 -3

void assert_double_array(double t1[], double t2[], int size) {
    for (int i = 0; i < size; i++) {
        mu_assert_double_eq(t1[i], t2[i]);
    }
}

// stack tests --------------------------------------------------------------------------------------------------------
MU_TEST(stack_test1) {
    for (int i = 0; i < STACK_SIZE; i++) {
        mu_assert_int_eq(OK ,stack_push(i));
    }
    for (int i = 10; i < 20; i++) {
        mu_assert_int_eq(OVERFLOW1, stack_push(i));
    }
    mu_assert_int_eq(FULL, stack_state());
    for (int i = STACK_SIZE - 1; i >= 0; i--) {
        mu_assert_double_eq(i, stack_pop());
    }
    for (int i = 0; i < 10; i++) {
        mu_assert_double_eq(NAN, stack_pop());
    }
    reset_stack();
}

MU_TEST(stack_test2) {
    stack_push(3);
    stack_push(7);
    stack_push(10);
    mu_assert_int_eq(10 ,stack_pop());
    mu_assert_int_eq(7 ,stack_pop());
    stack_push(11);
    mu_assert_int_eq(11 ,stack_pop());

}
// stack tests --------------------------------------------------------------------------------------------------------

// FIFO test ----------------------------------------------------------------------------------------------------------
// FIFO test ----------------------------------------------------------------------------------------------------------

// cbuff test ---------------------------------------------------------------------------------------------------------
// cbuff test ---------------------------------------------------------------------------------------------------------

MU_TEST_SUITE(stack_tests) {
    MU_RUN_TEST(stack_test1);
    MU_RUN_TEST(stack_test2);
}

MU_TEST_SUITE(fifo_tests) {

}

MU_TEST_SUITE(cbuff_tests) {

}

int main(void) {
    MU_RUN_SUITE(stack_tests);
    MU_RUN_SUITE(fifo_tests);
    MU_RUN_TEST(cbuff_tests);
    MU_REPORT();
    return MU_EXIT_CODE;
}
