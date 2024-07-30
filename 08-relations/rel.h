#ifndef REL_H
#define REL_H

#define TRUE 1
#define FALSE 0

#define MAX_REL_SIZE 1000


typedef struct {
    int first;
    int second;
} Pair;


// Add pair to existing relation if not already there
int add_to_relation(Pair* pairs, int relation_size, Pair pair);


// The relation R is reflexive if xRx for every x in X
int is_reflexive(Pair* pairs, int relation_size, const int *domain, int domain_size);


// The relation R on the set X is called irreflexive
// if xRx is false for every x in X
int is_irreflexive(Pair* pairs, int relation_size, const int *domain, int domain_size) ;


// A binary relation R over a set X is symmetric if:
// for all x, y in X xRy <=> yRx
int is_symmetric(Pair* pairs, int relation_size);


// A binary relation R over a set X is antisymmetric if:
// for all x,y in X if xRy and yRx then x=y
int is_antisymmetric(Pair* pairs, int relation_size);


// A binary relation R over a set X is asymmetric if:
// for all x,y in X if at least one of xRy and yRx is false
int is_asymmetric(Pair* pairs, int relation_size);


// A homogeneous relation R on the set X is a transitive relation if:
// for all x, y, z in X, if xRy and yRz, then xRz
int is_transitive(Pair* pairs, int relation_size);


// Relation R is connected if for each x, y in X:
// xRy or yRx (or both)
int is_connected(Pair* pairs, int relation_size, int *domain, int domain_size);


// A partial order relation is a homogeneous relation that is
// reflexive, transitive, and antisymmetric
int is_partial_order(Pair* pair, int relation_size, int *domain, int domain_size);


// A total order relation is a partial order relation that is connected
int is_total_order(Pair* pair, int relation_size, int *domain, int domain_size);


int find_max_elements(Pair* pairs, int relation_size, int* max_set, const int *domain, int domain_size);


int find_min_elements(Pair* pairs, int relation_size, int* min_set, const int *domain, int domain_size);


int get_domain(Pair* pairs, int relation_size , int* domain);


int composition (Pair* pairs1, int relation_size1, Pair* pairs2, int relation_size2, Pair* composition_pairs);


#endif

