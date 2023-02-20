#include <stdio.h>
#include <math.h> // for NAN

#define STACK_SIZE 10

#define OK 0
#define EMPTY -1
#define FULL -2
#define OVERFLOW1 -3

//STACK--------------------------------------------
double stack[STACK_SIZE];
int top = 0;

int stack_push(double x) {
    if (top == STACK_SIZE) {
        return OVERFLOW1;
    }
    stack[top] = x;
    top++;
    return OK;
}

double stack_pop(void) {
    if (top == 0) {
        return NAN;
    }
    top--;
    return stack[top];
}

int stack_state(void) {
    if (top == STACK_SIZE)
        return FULL;
    else
        return top;
}

void reset_stack(void) {
    top = 0;
}
//STACK--------------------------------------------

//FIFO queue with shifts---------------------------
#define QUEUE_SIZE 10

int queue[QUEUE_SIZE];
int in = 0, curr_nr = 0;


void queue_push(int in_nr) {
    for (int i = 0; i < in_nr; i++) {
        if (in == QUEUE_SIZE) {
            printf("OVERFLOW ");
            break;
        }
        queue[in] = curr_nr + i + 1;
        in++;
    }
    curr_nr += in_nr;
}


void queue_pop(int out_nr) {
    if (out_nr > in) {
        printf("UNDERFLOW");
        return;
    }
    for (int i = 0; i < in-out_nr; i++)
        queue[i] = queue[out_nr+i];
    in -= out_nr;
}


void queue_state(void) {
    if (in == 0) {
        printf("EMPTY ");
        return;
    }
    for (int i = 0; i < in; i++) {
        printf("%d ",queue[i]);
    }
}
//FIFO queue with shifts---------------------------

//Queue-with-cyclic-buffer-------------------------
#define CBUFF_SIZE 10

int cbuff[CBUFF_SIZE];
int out = 0, len = 0;


void cbuff_push(int cli_nr) {
    if (len == CBUFF_SIZE) {
        printf("OVERFLOW ");
        return;
    }
    int index = out;
    len++;
    for (int i = 0; i < len - 1; i++) {
        if (index + 1 < CBUFF_SIZE) {
            index++;
        } else {
            index = 0;
        }
    }
    cbuff[index] = cli_nr;
}

void cbuff_pop(void) {
    if (len == 0) {
        printf("UNDERFLOW ");
        return;
    }
    if (out == CBUFF_SIZE - 1) {
        out = 0;
    } else {
        out += 1;
    }
    len--;
}

void cbuff_state(void) {
    if (len == 0) {
        printf("EMPTY ");
        return;
    }
    int index = out;
    for (int i = 0; i < len; i++){
        printf("%d ", cbuff[index]);
        if (index + 1 < CBUFF_SIZE) {
            index++;
        } else {
            index = 0;
        }
    }
}
//Queue-with-cyclic-buffer-------------------------


