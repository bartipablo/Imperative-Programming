#ifndef SORT_H
#define SORT_H

#define MAX_BUFF 1024
#define MAX_STR_LEN 64
#define MAX_PERSONS 1024

#include <string.h>
#include <stdio.h>

typedef struct Person {
    int age;
    char first_name[MAX_STR_LEN];
    char last_name[MAX_STR_LEN];
} Person;

// Sort according to age (decreasing)
// When ages equal compare first name and then last name
int cmp_person(const void *p1, const void *p2);

// Read data to Person array (till EOF)
int read_person_array(Person *persons);

// Print Person array
void print_person_array(Person *persons, int n);

// Sort women first (woman's first name ends with 'a');
// Then sort women by age and men by last name
// Line consists of: age, first_name, last_name
// (int that order)
int cmp_lines(const void *l1, const void *l2);

// Read lines with students' data (as text)
int read_lines(char lines[][MAX_STR_LEN]);

// Print sorted lines
void print_lines(char lines[][MAX_STR_LEN], int n);

#endif