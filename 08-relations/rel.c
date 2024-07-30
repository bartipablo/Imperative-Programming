#include "rel.h"


int add_to_relation(Pair* pairs, int relation_size, Pair pair) {
    for (int i = 0; i < relation_size; i++) {
        if (pairs[i].first == pair.first && pairs[i].second == pair.second) {
            return FALSE;
        }
    }
    pairs[relation_size] = pair;
    return TRUE;
}


int is_reflexive(Pair* pairs, int relation_size, const int *domain, int domain_size) {
    for (int x = 0; x < domain_size; x++) {

        int found_reflexive_pair = FALSE;
        for (int i = 0; i < relation_size; i++) {
            if (pairs[i].first == domain[x] && pairs[i].second == domain[x]) {
                found_reflexive_pair = TRUE;
            }
        }

        if (!found_reflexive_pair) return FALSE;
    }
    return TRUE;
}


int is_irreflexive(Pair* pairs, int relation_size, const int *domain, int domain_size) {
    for (int x = 0; x < domain_size; x++) {

        for (int i = 0; i < relation_size; i++) {
            if (pairs[i].first == domain[x] && pairs[i].second == domain[x]) {
                return FALSE;
            }
        }
    }
    return TRUE;
}


int is_symmetric(Pair* pairs, int relation_size) {
    for (int x = 0; x < relation_size; x++) {
        int found_symmetric_pair = FALSE;

        for (int y = 0; y < relation_size; y++) {
            if (pairs[x].first == pairs[y].second && pairs[x].second == pairs[y].first) {
                found_symmetric_pair = TRUE;
                break;
            }
        }

        if (!found_symmetric_pair) {
            return FALSE;
        }
    }

    return TRUE;
}


int is_antisymmetric(Pair* pairs, int relation_size) {
    for (int x = 0; x < relation_size; x++) {

        for (int y = x; y < relation_size; y++) {
            if (pairs[x].first == pairs[y].second && pairs[x].second == pairs[y].first
                && pairs[x].first != pairs[x].second) {
                return FALSE;
            }
        }
    }

    return TRUE;
}


int is_asymmetric(Pair* pairs, int relation_size) {
    for (int x = 0; x < relation_size; x++) {

        for (int y = x; y < relation_size; y++) {
            if (pairs[x].first == pairs[y].second && pairs[x].second == pairs[y].first) {
                return FALSE;
            }
        }
    }

    return TRUE;
}


int is_transitive(Pair* pairs, int relation_size) {
    for (int x = 0; x < relation_size; x++) {
        for (int y = 0; y < relation_size; y++) {
            if (pairs[x].second == pairs[y].first) {
                int found_pair = FALSE;
                for (int z = 0; z < relation_size; z++) {
                    if (pairs[z].first == pairs[x].first && pairs[z].second == pairs[y].second) {
                        found_pair = TRUE;
                        break;
                    }
                }
                if (!found_pair) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}


static int is_pair_connected(Pair* pairs, int relation_size, int a, int b) {
    if (a == b) {
        return TRUE;
    }

    for (int x = 0; x < relation_size; x++) {
        if ((pairs[x].first == a && pairs[x].second == b) ||
                (pairs[x].second == a && pairs[x].first == b)) {
            return TRUE;
        }
    }

    return FALSE;
}


int is_connected(Pair* pairs, int relation_size, int *domain, int domain_size) {
    for (int x = 0; x < domain_size; x++) {
        for (int y = x; y < domain_size; y++) {
            if (!is_pair_connected(pairs, relation_size, domain[x], domain[y])) {
                return FALSE;
            };
        }
    }
    return TRUE;
}


int is_partial_order(Pair* pairs, int relation_size, int *domain, int domain_size) {
    if (is_reflexive(pairs, relation_size, domain, domain_size) && is_transitive(pairs, relation_size) && is_antisymmetric(pairs, relation_size)) {
        return TRUE;
    }
    return FALSE;
}


int is_total_order(Pair* pairs, int relation_size, int *domain, int domain_size) {
    if (is_partial_order(pairs, relation_size, domain, domain_size) && is_connected(pairs, relation_size, domain, domain_size)) {
        return TRUE;
    }
    return FALSE;
}


static int find_extreme_elements(Pair* pairs, int relation_size, int* extreme_set, const int *domain, int domain_size, int is_max) {
    int extreme_set_size = 0;

    for (int x = 0; x < domain_size; x++) {
        int is_extreme = TRUE;
        for (int i = 0; i < relation_size; i++) {
            if (is_max) {
                if (pairs[i].first == domain[x] && pairs[i].second != domain[x]) {
                    is_extreme = FALSE;
                    break;
                }
            } else {
                if (pairs[i].second == domain[x] && pairs[i].first != domain[x]) {
                    is_extreme = FALSE;
                    break;
                }
            }
        }

        if (is_extreme) {
            extreme_set[extreme_set_size] = domain[x];
            extreme_set_size++;
        }
    }

    return extreme_set_size;
}


int find_max_elements(Pair* pairs, int relation_size, int* max_set, const int *domain, int domain_size) {
    return find_extreme_elements(pairs, relation_size, max_set, domain, domain_size, TRUE);
}


int find_min_elements(Pair* pairs, int relation_size, int* min_set, const int *domain, int domain_size) {
    return find_extreme_elements(pairs, relation_size, min_set, domain, domain_size, FALSE);
}


static int add_to_domain_if_not_exist(int val, int *domain, int domain_size) {
    for (int i = 0; i < domain_size; i++) {
        if (domain[i] == val) {
            return FALSE;
        }
    }
    domain[domain_size] = val;
    return TRUE;
}


int get_domain(Pair* pairs, int relation_size , int* domain) {
    int domain_size = 0;

    for (int i = 0; i < relation_size; i++) {
        int added_first = add_to_domain_if_not_exist(pairs[i].first, domain, domain_size);
        if (added_first) domain_size++;

        int added_second = add_to_domain_if_not_exist(pairs[i].second, domain, domain_size);
        if (added_second) domain_size++;
    }

    return domain_size;
}


int composition(Pair* pairs1, int relation_size1, Pair* pairs2, int relation_size2, Pair* composition_pairs) {
    int composition_relation_size = 0;

    for (int x = 0; x < relation_size1; x++) {
        for (int y = 0; y < relation_size2; y++) {

            if (pairs1[x].second == pairs2[y].first) {
                Pair new_pair = {pairs1[x].first, pairs2[y].second};
                int added = add_to_relation(composition_pairs, composition_relation_size, new_pair);
                if (added) composition_relation_size++;
            }
        }
    }
    return composition_relation_size;
}