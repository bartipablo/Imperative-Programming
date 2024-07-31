#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STR_LEN 64

#include "vector.h"


typedef struct Person {
    int age;
    char first_name[MAX_STR_LEN];
    char last_name[MAX_STR_LEN];
} Person;


void print_vector_int(Vector *vector) {
    printf("%zu\n", vector->size);
    for (int i = 0; i < vector->size; i++) {
        int* val = (int*) vector->data + i;
        printf("%d ", *val);
    }
}


// Print char vector
void print_vector_char(Vector *vector) {
    printf("%zu\n", vector->size);
    for (int i = 0; i < vector->size; i++) {
        char* c = (char*) vector->data + i;
        printf("%c ", *c);
    }
}


// Print vector of Person
void print_vector_person(Vector *vector) {
    printf("%zu\n", vector->size);
    for (int i = 0; i < vector->size; i++) {
        Person* person = (Person *) vector->data + i;
        printf("%d %s %s\n", person->age, person->first_name, person->last_name);
    }
}


// integer comparator - increasing order
int int_cmp(const void *v1, const void *v2) {
    int val1 = *(const int *)v1;
    int val2 = *(const int *)v2;

    return (val1 > val2) - (val1 < val2);
}


// char comparator - lexicographical order (case sensitive)
int char_cmp(const void *v1, const void *v2) {
    char c1 = *(const char *)v1;
    char c2 = *(const char *)v2;

    return (c1 > c2) - (c1 < c2);
}


// Person comparator:
// Sort according to age (decreasing)
// When ages equal compare first name and then last name
int person_cmp(const void *p1, const void *p2) {
    Person *person1 = (Person*) p1;
    Person *person2 = (Person*) p2;

    if (person1->age != person2->age) {
        return person2->age - person1->age;
    }

    if (strcmp(person1->first_name, person2->first_name) != 0) {
        return strcmp(person1->first_name, person2->first_name);
    }

    return strcmp(person1->last_name, person2->last_name);
}


// predicate: check if number is even
int is_even(void *value) {
    int *val_ptr = (int *) value;
    int val = *val_ptr;
    return val % 2 == 0;
}


int is_vowel(void *value) {
    char *val = (char *)value;
    char ch = *val;

    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}


// predicate: check if person is older than 25
int is_older_than_25(void *person) {
    Person *person_ptr = (Person*) person;
    return person_ptr->age > 25;
}


void read_int(void* value) {
    scanf("%d", (int*)value);
}


void read_char(void* value) {
    char c[2];
    scanf("%s", c);
    *(char*)value = c[0];
}


void read_person(void* value) {
    Person *person = (Person*)value;
    scanf("%d %s %s", &person->age, person->first_name, person->last_name);
}


void vector_test(Vector *vector, int n, void(*read)(void*),
                 int (*cmp)(const void*, const void*), int(*predicate)(void*)) {
    char op[2];
    int index;
    size_t size;
    void *v = malloc(vector->element_size);
    int stop = 0;

    for (int i = 0; i < n && !stop; ++i) {
        scanf("%s", op);
        switch (op[0]) {
            case 'p': // push_back
                read(v);
                push_back(vector, v);
                break;
            case 'i': // insert
                scanf("%d", &index);
                read(v);
                insert(vector, index, v);
                break;
            case 'e': // erase
                scanf("%d", &index);
                read(v);
                erase(vector, index);
                erase_value(vector, v, cmp);
                break;
            case 'd': // erase (predicate)
                erase_if(vector, predicate);
                break;
            case 'r': // resize
                scanf("%zu", &size);
                resize(vector, size);
                break;
            case 'c': // clear
                clear(vector);
                break;
            case 'f': // shrink
                shrink_to_fit(vector);
                break;
            case 's': // sort
                qsort(vector->data, vector->size,
                      vector->element_size, cmp);
                break;
            case 'b':
                pop_back(vector);
                break;
            case 'x':
                stop = 1;
                break;
            default:
                printf("No such operation: %s\n", op);
                break;
        }
    }
    free(v);
}


int main(void) {
    int to_do, n;
    Vector vector_int, vector_char, vector_person;

    scanf("%d%d", &to_do, &n);

    switch (to_do) {
        case 1:
            init_vector(&vector_int, 4, sizeof(int));
            vector_test(&vector_int, n, read_int, int_cmp, is_even);
            print_vector_int(&vector_int);
            free(vector_int.data);
            break;
        case 2:
            init_vector(&vector_char, 2, sizeof(char));
            vector_test(&vector_char, n, read_char, char_cmp, is_vowel);
            print_vector_char(&vector_char);
            free(vector_char.data);
            break;
        case 3:
            init_vector(&vector_person, 2, sizeof(Person));
            vector_test(&vector_person, n, read_person, person_cmp, is_older_than_25);
            print_vector_person(&vector_person);
            free(vector_person.data);
            break;
        default:
            printf("Nothing to do for %d\n", to_do);
            break;
    }

    return 0;
}

