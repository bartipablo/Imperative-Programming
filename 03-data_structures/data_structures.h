#ifndef DATA_H
#define DATA_H

#define OK 0
#define EMPTY -1
#define FULL -2
#define OVERFLOW1 -3

#define STACK_SIZE 10
#define QUEUE_SIZE 10
#define CBUFF_SIZE 10

static double stack[STACK_SIZE];
static int top = 0;

int stack_push(double x);

double stack_pop(void);

int stack_state(void);

void reset_stack(void);

static int queue[QUEUE_SIZE];
static int in = 0, curr_nr = 0;

void queue_push(int in_nr);

void queue_pop(int out_nr);

void queue_state(void);

static int cbuff[CBUFF_SIZE];
static int out = 0, len = 0;

void cbuff_push(int cli_nr);

void cbuff_pop(void);

void cbuff_state(void);

#endif
