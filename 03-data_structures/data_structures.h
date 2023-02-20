#ifndef MY_HEADER_H
#define MY_HEADER_H

int stack_push(double x);

double stack_pop(void);

int stack_state(void);

void reset_stack(void);

void queue_push(int in_nr);

void queue_pop(int out_nr);

void queue_state(void);

void cbuff_push(int cli_nr);

void cbuff_pop(void);

void cbuff_state(void);

#endif