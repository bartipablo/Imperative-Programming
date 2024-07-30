#include <stdio.h>

#include "rel.h"

// Read number of pairs, n, and then n pairs of ints
int read_relation(Pair* pairs) {
    int n = 0;
    scanf("%d",&n);

    int size = 0;
    int first, second;
    for (int i = 0; i < n; i++) {
        scanf("%d", &first);
        scanf("%d", &second);
        Pair new_pair = {first, second};
        int added = add_to_relation(pairs, size, new_pair);
        if (added == TRUE) {
            size++;
        }
    }

    return size;
}


void print_int_array(int *array, int n) {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(void) {
    int to_do;
    Pair relation[MAX_REL_SIZE];
    Pair relation_2[MAX_REL_SIZE];
    Pair comp_relation[MAX_REL_SIZE];
    int domain[MAX_REL_SIZE * 2];

    scanf("%d",&to_do);
    int relation_size = read_relation(relation);
    int domain_size = get_domain(relation, relation_size, domain);

    int ordered, size_2, n_domain;

    switch (to_do) {
        case 1:
            printf("%d ", is_reflexive(relation, relation_size, domain, domain_size));
            printf("%d ", is_irreflexive(relation, relation_size, domain, domain_size));
            printf("%d ", is_symmetric(relation, relation_size));
            printf("%d ", is_antisymmetric(relation, relation_size));
            printf("%d ", is_asymmetric(relation, relation_size));
            printf("%d\n", is_transitive(relation, relation_size));
            break;
        case 2:
            ordered = is_partial_order(relation, relation_size, domain, domain_size);
            n_domain = get_domain(relation, relation_size, domain);
            printf("%d %d\n", ordered, is_total_order(relation, relation_size, domain, domain_size));
            print_int_array(domain, n_domain);
            if (!ordered) break;
            int max_elements[MAX_REL_SIZE];
            int min_elements[MAX_REL_SIZE];
            int no_max_elements = find_max_elements(relation, relation_size, max_elements, domain, domain_size);
            int no_min_elements = find_min_elements(relation, relation_size, min_elements, domain, domain_size);
            print_int_array(max_elements, no_max_elements);
            print_int_array(min_elements, no_min_elements);
            break;
        case 3:
            size_2 = read_relation(relation_2);
            printf("%d\n", composition(relation, relation_size,
                                       relation_2, size_2, comp_relation));
            break;
        default:
            printf("NOTHING TO DO FOR %d\n", to_do);
            break;
    }
    return 0;
}

