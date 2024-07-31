//The program searches the input string by successive characters.
//we have 5 different cases:
//-in the id
//-in the block comment
//-in the string
//-in line comment
//-unidentified

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define UNDEFINED 0
#define IN_BLOCK_COMMENT 2
#define IN_STRING 4
#define IN_ID 8

#define MAX_ID_LEN 64
#define MAX_IDS 1024
#define MAX_LINE 1024

int cmp(const void*, const void*);
int is_new_id(const char*, int index);

char tab[MAX_IDS][MAX_ID_LEN];
int result = 0;
int status = UNDEFINED;

char *keywords[] = {
        "auto", "break", "case", "char",
        "const", "continue", "default", "do",
        "double", "else", "enum", "extern",
        "float", "for", "goto", "if",
        "int", "long", "register", "return",
        "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
};


int find_idents() {
    char temp_string[MAX_LINE];
    int temp_index = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        int i = 0;
        while (line[i] != '\0') {
            if (status == IN_ID) {
                if ((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'A' && line[i] <= 'Z') ||
                    (line[i] >= 'a' && line[i] <= 'z') || line[i] == '_') {
                    temp_string[temp_index] = line[i];
                    temp_index++;
                    i++;
                } else {
                    temp_string[temp_index] = '\0';
                    if (is_new_id(temp_string, temp_index)) {
                        result++;
                    }
                    status = UNDEFINED;
                    temp_index = 0;
                }
            } else if (status == UNDEFINED) {
                if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || line[i] == '_') {
                    temp_string[temp_index] = line[i];
                    temp_index++;
                    status = IN_ID;
                } else if (i > 0 && (line[i] == '/' && line[i-1] == '/')) {
                    break;   // line comment case
                } else if (i > 0 && (line[i] == '*' && line[i-1] == '/')) {
                    status = IN_BLOCK_COMMENT;
                } else if (line[i] == '"') {
                    status = IN_STRING;
                }
                i++;
            } else if (status == IN_BLOCK_COMMENT) {
                if (i > 0 && (line[i] == '/' && line[i-1] == '*')) {
                    status = UNDEFINED;
                }
                i++;
            } else if (status == IN_STRING) {
                if (line[i] == '"') {
                    status = UNDEFINED;
                }
                i++;
            }
        }
    }
    return result;
}


int is_new_id(const char* id, int index) {
    for (int i = 0; i < result; i++) {
        if (!cmp(tab[i], id)) return FALSE;
    }
    for (int i = 0; i < 32; i++) {
        if (!cmp(keywords[i], id)) return FALSE;
    }
    strcpy(tab[result], id);
    return TRUE;
}


int cmp(const void* first_arg, const void* second_arg) {
    char *a = (char*)first_arg;
    char *b = (char*)second_arg;
    return strcmp(a, b);
}


int main(void) {
    printf("%d\n", find_idents());
    return 0;
}
