#include <stdio.h>
#include <stdlib.h>

#include "sort.h"


int read_int() {
    char buf[MAX_STR_LEN];
    int n;
    fgets(buf, MAX_STR_LEN, stdin);
    sscanf(buf, "%d", &n);
    return n;
}


int main(void) {
    int to_do = read_int();
    int n;
    Person persons[MAX_PERSONS];
    char lines[MAX_PERSONS][MAX_STR_LEN];
    switch (to_do) {
        case 1:
            n = read_person_array(persons);
            qsort(persons, (size_t)n, sizeof(Person), cmp_person);
            print_person_array(persons, n);
            break;
        case 2:
            n = read_lines(lines);
            qsort(lines, (size_t) n, MAX_STR_LEN, cmp_lines);
            print_lines(lines, n);
            break;
        default:
            printf("Nothing to do for %d\n", to_do);
            break;
    }
}

