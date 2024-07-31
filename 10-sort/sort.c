#include "sort.h"

int cmp_person(const void *p1, const void *p2) {
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


int read_person_array(Person *persons) {
    int count = 0;
    char line[MAX_BUFF];

    while (fgets(line, sizeof(line), stdin) != NULL) {

        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue;

        int age;
        char first_name[MAX_STR_LEN];
        char last_name[MAX_STR_LEN];

        sscanf(line, "%d %s %s", &age, first_name, last_name);

        persons[count].age = age;
        strncpy(persons[count].first_name, first_name, MAX_STR_LEN);
        strncpy(persons[count].last_name, last_name, MAX_STR_LEN);
        count++;
    }

    return count;
}


void print_person_array(Person *persons, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %s\n", persons[i].age, persons[i].first_name, persons[i].last_name);
    }
}


int cmp_lines(const void *l1, const void *l2) {
    char* line1 = (char*) l1;
    char* line2 = (char*) l2;

    int age1, age2;
    char first_name1[MAX_STR_LEN], first_name2[MAX_STR_LEN];
    char last_name1[MAX_STR_LEN], last_name2[MAX_STR_LEN];

    sscanf(line1, "%d %s %s", &age1, first_name1, last_name1);
    sscanf(line2, "%d %s %s", &age2, first_name2, last_name2);

    char first_name1_ending = first_name1[strlen(first_name1) - 1];
    char first_name2_ending = first_name2[strlen(first_name2) - 1];

    if (first_name1_ending == 'a' && first_name2_ending != 'a') {
        return -1;
    }
    else if (first_name1_ending != 'a' && first_name2_ending == 'a') {
        return 1;
    }
    else if (first_name1_ending == 'a' && first_name2_ending == 'a') {
        return age1 - age2;
    }
    return strcmp(last_name1, last_name2);
}


int read_lines(char lines[][MAX_STR_LEN]) {
    int count = 0;
    char line[MAX_BUFF];

    while (fgets(line, sizeof(line), stdin) != NULL) {

        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue;
        strcpy(lines[count], line);
        count++;
    }

    return count;
}


void print_lines(char lines[][MAX_STR_LEN], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", lines[i]);
    }
}