#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define UNIDENTIFIED 0
#define IN_LINE_COMMENT 1
#define IN_BLOCK_COMMENT 2
#define IN_STRING 3
#define IN_CHR 4
#define IN_ID 5

#define KEYWORDS 32

#define MAX_ID_LEN 64
#define MAX_IDS 1024
#define MAX_LINES 128

int index_cmp(const void*, const void*);
int cmp(const void*, const void*);
int string_comparing(const char*, const char*);

char tab[MAX_IDS][MAX_ID_LEN];

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

int find_idents(){

    int result = 0; //licznik znalezionych identyfikatorów
    int meter = 0; //licznik znalezionych słów
    int status = UNIDENTIFIED;
    char new_id[MAX_LINES];
    char line[MAX_LINES];
    int flag;


    while (fgets(line, MAX_LINES, stdin) != NULL){
        int i = 0;  //Aktualnie rozpatrywany indeks w line
        int k = 0;  //D³ugoœæ znalezionego identyfikatora

        if (status == IN_BLOCK_COMMENT)
            ;
        else if (((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z')) ||
        (line[i] == '_')){
            k = 0;
            status = IN_ID;
            new_id[k] = line[i];
            k++;
        }
        else if (line[i] == '\'')
            status = IN_CHR;
        else if (line[i] == '"')
            status = IN_STRING;
        else
            status = UNIDENTIFIED;
        i++;

        while (line[i] != '\0'){
            if ((status == IN_BLOCK_COMMENT) || (status == IN_LINE_COMMENT) ||
            (status == IN_CHR) || (status == IN_STRING)){
                if (status == IN_LINE_COMMENT)
                    break;
                else if ((status == IN_BLOCK_COMMENT)&&(line[i-1]=='*')&&(line[i]=='/'))
                    status = UNIDENTIFIED;
                else if ((status == IN_STRING)&&(line[i] == '"'))
                    status = UNIDENTIFIED;
                else if ((status == IN_CHR)&&(line[i] == '\''))
                    status = UNIDENTIFIED;
            }
            else if (status == UNIDENTIFIED){
                if (line[i] == '"')
                    status = IN_STRING;
                else if (line[i] == '\'')
                    status = IN_CHR;
                else if ((line[i] == '/')&&(line[i-1] == '/'))
                    break;
                else if ((line[i-1] == '/')&&(line[i] == '*'))
                    status = IN_BLOCK_COMMENT;
                else if (((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z')) ||
                (line[i] == '_')){
                    k = 0;
                    new_id[k] = line[i];
                    status = IN_ID;
                    k++;
                }
            }
            else if (status == IN_ID){
                if (((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z')) ||
                (line[i] == '_') || ((line[i] >= '0') && (line[i] <= '9'))){
                    new_id[k] = line[i];
                    k++;
                }
                else{
                    new_id[k] = '\0';
                    if (add_unique(&tab, &new_id, meter))
                        meter++;
                    k = 0;
                    if (line[i] == '"')
                        status = IN_STRING;
                    else if (line[i] == '\'')
                        status = IN_CHR;
                    else
                        status = UNIDENTIFIED;
                }
            }
        i++;
        }
    }
    for (int i=0; i<meter; i++){
        flag = TRUE;
        for (int j=0; j<KEYWORDS; j++){
            if (string_comparing(keywords[j],&tab[i])){
                flag = FALSE;
                break;
            }
        }
        if (flag)
            result++;
    }
    return result;
}

//------------------------------------

int string_comparing(const char *X,const char *Y){

    int i = 0;
    while ((X[i] != '\0')&&(Y[i] != '\0')){
        if (X[i] == Y[i])
            i++;
        else
            break;
    }
    if (X[i] == Y[i]) return TRUE;
    else              return FALSE;
}

int add_unique(char X[][MAX_ID_LEN], const char *Y, int meter){
    for (int i=0; i<meter; i++){
        if (string_comparing(&X[i][0], Y))
            return FALSE;
    }
    sscanf(Y,"%s",&X[meter]);
    return TRUE;
}

//int cmp(const void* first_arg, const void* second_arg) {
//	char *a = *(char**)first_arg;
//	char *b = *(char**)second_arg;
//	return strcmp(a, b);
//}

//int index_cmp(const void* first_arg, const void* second_arg) {
//	int a = *(int*)first_arg;
//	int b = *(int*)second_arg;
//	return strcmp(tab[a], tab[b]);
//}

int main(void) {
	printf("%d\n", find_idents());
	return 0;
}

