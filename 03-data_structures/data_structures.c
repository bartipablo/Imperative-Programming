#include <stdio.h>
#include <math.h> // for NAN

#include "data_structures.h"

//STACK--------------------------------------------
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


