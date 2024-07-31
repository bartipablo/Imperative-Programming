#include <stdio.h>
#include <stdlib.h>

// consider chars from [FIRST_CHAR, LAST_CHAR]
#define FIRST_CHAR 32
#define LAST_CHAR 126
#define MAX_CHARS ((LAST_CHAR - FIRST_CHAR) + 1)
#define MAX_DIGRAMS ((LAST_CHAR - FIRST_CHAR + 1) * (LAST_CHAR - FIRST_CHAR + 1))
#define MAX_LINE 128

#define OUT_WORD 0
#define IN_WORD 1
#define OUT_COMMENT 0
#define IN_BLOCK_COMMENT 1

int count[MAX_DIGRAMS] = {0};


// function to be used as comparator to qsort (compares counters and thes sorts
// alphabetically when equal)
int cmp (const void *a, const void *b) {
	int va = *(int*)a;
	int vb = *(int*)b;
	if (count[va] == count[vb]) return va - vb; // sort alphabetically if counts equal
	return count[vb] - count[va];
}


// function to be used as comparator to qsort for diagrams (compares counters and
// these sorts alphabetically when equal)
int cmp_di (const void *a, const void *b) {
	int va = *(int*)a;
	int vb = *(int*)b;
	// sort according to second char if counts and the first char equal
	if (count[va] == count[vb] && va / MAX_CHARS == vb / MAX_CHARS) return va % MAX_CHARS - vb % MAX_CHARS;
	// sort according to first char if counts equal
	if (count[va] == count[vb]) return va / MAX_CHARS - vb / MAX_CHARS;
	return count[vb] - count[va];
}


// count number of lines (nl), number of words (nw) and number of characters
// (nc) in the text read from stdin
void wc(int *nl, int *nw, int *nc) {
    int state = OUT_WORD;
    *nl = 0;
    *nw = 0;
    *nc = 0;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        (*nl)++;
        int i = 0;
        while (line[i] != '\0') {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
                state = OUT_WORD;
            } else if (state == OUT_WORD) {
                state = IN_WORD;
                (*nw)++;
            }
            i++;
        }
        *nc += i;
    }
}


// count how many times each character from [FIRST_CHAR, LAST_CHAR) occurs
// in the text read from stdin. Sort chars according to their respective
// cardinalities (decreasing order). Set n_char and cnt to the char_no - th char
// in the sorted list and its cardinality respectively
void char_count(int char_no, int *n_char, int *cnt) {
    int index[MAX_CHARS];
    char line[MAX_LINE];
    for (int i = 0; i < MAX_CHARS; i++) {
        index[i] = i;
    }
    while (fgets(line, MAX_LINE, stdin) != NULL) {
         int i = 0;
         while (line[i] != '\0') {
            if ((line[i] >= FIRST_CHAR) && (line[i] <= LAST_CHAR)) {
                count[line[i] - FIRST_CHAR] += 1;
            }
            i++;
         }
    }
    qsort(index, MAX_CHARS, sizeof(int), cmp);
    *n_char = index[char_no-1] + FIRST_CHAR;
    *cnt    = count[*n_char - FIRST_CHAR];
}


// count how many times each digram (a pair of characters, from [FIRST_CHAR,
// LAST_CHAR) each) occurs in the text read from stdin. Sort digrams according
// to their respective cardinalities (decreasing order). Set digram[0] and
// digram[1] to the first and the second char in the digram_no - th digram_char
// in the sorted list. Set digram[2] to its cardinality.
void digram_count(int digram_no, int digram[]) {
    int index[MAX_DIGRAMS];
    char line[MAX_LINE];
    for (int i = 0; i < MAX_DIGRAMS; i++) {
        index[i] = i;
    }

    while (fgets(line, MAX_LINE, stdin) != NULL) {
         int i = 1;
         while (line[i] != '\0') {
            if (((line[i] >= FIRST_CHAR) && (line[i] <= LAST_CHAR)) && ((line[i-1] >= FIRST_CHAR) && (line[i-1] <= LAST_CHAR))) {
                count[MAX_CHARS*(line[i-1] - FIRST_CHAR) + (line[i] - FIRST_CHAR)] += 1;
            }
            i++;
         }
    }
    qsort(index, MAX_DIGRAMS, sizeof(int), cmp_di);
    int y = count[6240];
    int x = index[digram_no-1];
    digram[0] = x/MAX_CHARS + FIRST_CHAR;
    digram[1] = x%MAX_CHARS + FIRST_CHAR;
    digram[2] = count[x];
}


// Count block and line comments in the text read from stdin. Set
// line_comment_counter and block_comment_counter accordingly
void find_comments(int *line_comment_counter, int *block_comment_counter) {
    *line_comment_counter = 0;
    *block_comment_counter = 0;
    char line[MAX_LINE];
    int position = OUT_COMMENT;
    while (fgets(line, MAX_LINE, stdin) != NULL){
        int i = 1;
        while (line[i] != '\0'){
            if ((!position) && (line[i] == '/') && (line[i - 1] == '/')) {
                (*line_comment_counter)++;
                break;
            }
            else if ((!position) && (line[i] == '*') && (line[i - 1] == '/')){
                position = IN_BLOCK_COMMENT;
                (*block_comment_counter)++;
            }
            else if ((position) && (line[i] == '/') && (line[i - 1] == '*')){
                position = OUT_COMMENT;
            }
            i++;
        }
    }
}


int read_line() {
	char line[MAX_LINE];
	int n;
	fgets (line, MAX_LINE, stdin); // to get the whole line
	sscanf (line, "%d", &n);
	return n;
}


int main(void) {
	int to_do;
	int nl, nw, nc, char_no, n_char, cnt;
	int line_comment_counter, block_comment_counter;
	int digram[3];

	to_do = read_line();
	switch (to_do) {
		case 1: // wc()
			wc (&nl, &nw, &nc);
			printf("%d %d %d\n", nl, nw, nc);
			break;
		case 2: // char_count()
			char_no = read_line();
			char_count(char_no, &n_char, &cnt);
			printf("%c %d\n", n_char, cnt);
			break;
		case 3: // digram_count()
			char_no = read_line();
			digram_count(char_no, digram);
			printf("%c%c %d\n", digram[0], digram[1], digram[2]);
			break;
		case 4:
			find_comments(&line_comment_counter, &block_comment_counter);
			printf("%d %d\n", block_comment_counter, line_comment_counter);
			break;
		default:
			printf("NOTHING TO DO FOR %d\n", to_do);
			break;
	}
	return 0;
}

