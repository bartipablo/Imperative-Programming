#include "../minunit.h"
#include "rel.h"

#define SIZE 10
#define SMALL_SIZE 3


/* ***************************************************
 * DATA
 *************************************************** */

// reflexive
// NOT irreflexive
// NOT symetric
// NOT antisymetric
// NOT asymetric
// NOT transitive
// NOT connected
static int domain_1[] = {1, 2, 3, 4, 7, 8};
static int domain_1_size = 6;
static Pair pairs_1[SIZE] = {
        {1, 1},
        {1, 2},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5},
        {3, 1},
        {1, 3},
        {7, 7},
        {8,8}
};

// NOT reflexive
// NOT irreflexive
// NOT symetric
// NOT antisymetric
// NOT asymetric
// NOT transitive
// NOT connected
static int domain_2[] = {1, 5, 2, 3, 4, 7,8};
static int domain_2_size = 7;
static Pair pairs_2[SIZE] = {
        {1, 5},
        {1, 2},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5},
        {3, 1},
        {1, 3},
        {7, 7},
        {8,8}
};

// NOT reflexive
// irreflexive
// NOT symetric
// NOT antisymetric
// NOT asymetric
// NOT connected
static int domain_3[] = {1, 5, 2, 3, 9, 4, 10, 7, 2, 8};
static int domain_3_size = 10;
static Pair pairs_3[SIZE] = {
        {1, 5},
        {1, 2},
        {2, 1},
        {3, 9},
        {4, 1},
        {5, 10},
        {3, 10},
        {1, 3},
        {7, 2},
        {8,2}
};

// NOT reflexive
// NOT irreflexive
// symetric
// NOT antisymetric
// NOT asymetric
// NOT connected
static int domain_4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
static int domain_4_size = 9;
static Pair pairs_4[SIZE] = {
        {1, 2}, {2, 1},
        {2, 3}, {3, 2},
        {4, 5}, {5, 4},
        {6, 7}, {7, 6},
        {8, 8}, {9, 9}
};

// NOT reflexive
// NOT irreflexive
// NOT symetric
// antisymetric
// NOT asymetric
// NOT connected
static int domain_5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14 ,15};
static int domain_5_size = 14;
static Pair pairs_5[SIZE] = {
        {1, 2},
        {2, 2},
        {4, 5},
        {6, 7},
        {8, 9},
        {3, 4},
        {7, 8},
        {10, 10},
        {12, 13},
        {14, 15}
};

// NOT reflexive
// NOT irreflexive
// NOT symetric
// antisymetric
// asymetric
// NOT connected
static int domain_6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 ,20};
static int domain_6_size = 20;
static Pair pairs_6[SIZE] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20}
};

// transitive
// NOT connected
static int domain_7[] = {1, 4, 7, 9, 10, 11, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
static int domain_7_size = 17;
static Pair pairs_7[SIZE] = {
        {1, 4},
        {4, 7},
        {9, 10},
        {1, 7},
        {13, 11},
        {15, 16},
        {17, 18},
        {19, 20},
        {21, 22},
        {23, 24}
};

// transitive
// NOT connected
static int domain_8[] = {1, 4, 7, 9, 10};
static int domain_8_size = 5;
static Pair pairs_8[SMALL_SIZE] = {
        {1, 1},
        {4, 7},
        {9, 10}
};

//connected
static int domain_9[] = {1, 4, 7, 9};
static int domain_9_size = 4;
static Pair pairs_9[SIZE] = {
        {1, 9},
        {4, 7},
        {1, 7},
        {7, 1},
        {9, 4},
        {4, 7},
        {7, 7},
        {7, 9},
        {1, 4},
        {4, 4}
};
/* ***************************************************
 * DATA
 *************************************************** */


MU_TEST(is_reflexive_test) {
    mu_assert_int_eq(TRUE, is_reflexive(pairs_1, SIZE, domain_1, domain_1_size));
    mu_assert_int_eq(FALSE, is_reflexive(pairs_2, SIZE, domain_2, domain_2_size));
    mu_assert_int_eq(FALSE, is_reflexive(pairs_3, SIZE, domain_3, domain_3_size));
    mu_assert_int_eq(FALSE, is_reflexive(pairs_4, SIZE, domain_4, domain_4_size));
    mu_assert_int_eq(FALSE, is_reflexive(pairs_5, SIZE, domain_5, domain_5_size));
}

MU_TEST(is_irreflexive_test) {
    mu_assert_int_eq(FALSE, is_irreflexive(pairs_1, SIZE, domain_1, domain_1_size));
    mu_assert_int_eq(FALSE, is_irreflexive(pairs_2, SIZE, domain_2, domain_2_size));
    mu_assert_int_eq(TRUE, is_irreflexive(pairs_3, SIZE, domain_3, domain_3_size));
    mu_assert_int_eq(FALSE, is_irreflexive(pairs_4, SIZE, domain_4, domain_4_size));
    mu_assert_int_eq(FALSE, is_irreflexive(pairs_5, SIZE, domain_5, domain_5_size));
}

MU_TEST(is_symetric_test) {
    mu_assert_int_eq(FALSE, is_symmetric(pairs_1, SIZE));
    mu_assert_int_eq(FALSE, is_symmetric(pairs_2, SIZE));
    mu_assert_int_eq(FALSE, is_symmetric(pairs_3, SIZE));
    mu_assert_int_eq(TRUE, is_symmetric(pairs_4, SIZE));
    mu_assert_int_eq(FALSE, is_symmetric(pairs_5, SIZE));
}

MU_TEST(is_antisymetric_test) {
    mu_assert_int_eq(FALSE, is_antisymmetric(pairs_1, SIZE));
    mu_assert_int_eq(FALSE, is_antisymmetric(pairs_2, SIZE));
    mu_assert_int_eq(FALSE, is_antisymmetric(pairs_3, SIZE));
    mu_assert_int_eq(FALSE, is_antisymmetric(pairs_4, SIZE));
    mu_assert_int_eq(TRUE, is_antisymmetric(pairs_5, SIZE));
    mu_assert_int_eq(TRUE, is_asymmetric(pairs_6, SIZE));
}

MU_TEST(is_asymetric_test) {
    mu_assert_int_eq(FALSE, is_asymmetric(pairs_1, SIZE));
    mu_assert_int_eq(FALSE, is_asymmetric(pairs_2, SIZE));
    mu_assert_int_eq(FALSE, is_asymmetric(pairs_3, SIZE));
    mu_assert_int_eq(FALSE, is_asymmetric(pairs_4, SIZE));
    mu_assert_int_eq(FALSE, is_asymmetric(pairs_5, SIZE));
    mu_assert_int_eq(TRUE, is_asymmetric(pairs_6, SIZE));
}


MU_TEST(is_transitive_test) {
    mu_assert_int_eq(FALSE, is_transitive(pairs_1, SIZE));
    mu_assert_int_eq(FALSE, is_transitive(pairs_2, SIZE));
    mu_assert_int_eq(TRUE, is_transitive(pairs_7, SIZE));
    mu_assert_int_eq(TRUE, is_transitive(pairs_8, SMALL_SIZE));
}


MU_TEST(is_connected_test) {
    mu_assert_int_eq(FALSE, is_connected(pairs_1, SIZE, domain_1, domain_1_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_2, SIZE, domain_2, domain_2_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_3, SIZE, domain_3, domain_3_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_4, SIZE, domain_4, domain_4_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_5, SIZE, domain_5, domain_5_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_6, SIZE, domain_6, domain_6_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_7, SIZE, domain_7, domain_7_size));
    mu_assert_int_eq(FALSE, is_connected(pairs_8, SIZE, domain_8, domain_8_size));
    mu_assert_int_eq(TRUE, is_connected(pairs_9, SIZE, domain_9, domain_9_size));
}


MU_TEST_SUITE(homogeneous_relation) {
    MU_RUN_TEST(is_reflexive_test);
    MU_RUN_TEST(is_irreflexive_test);
    MU_RUN_TEST(is_symetric_test);
    MU_RUN_TEST(is_antisymetric_test);
    MU_RUN_TEST(is_asymetric_test);
    MU_RUN_TEST(is_transitive_test);
    MU_RUN_TEST(is_connected_test);
}

int main(void) {
    MU_RUN_SUITE(homogeneous_relation);
    MU_REPORT();
    return MU_EXIT_CODE;
}