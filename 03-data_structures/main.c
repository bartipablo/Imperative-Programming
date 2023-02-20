#include <stdio.h>
#include "data_structures.h"

int main(void) {
    int to_do, n, client_no, op_code;
    double x;
    scanf("%d",&to_do);
    switch(to_do) {
        case 1: // stack
            do {
                scanf("%lf",&x);
                if(x > 0) stack_push(x);
                else {
                    if(x < 0) printf("%.2f ", stack_pop());
                    else printf("\n%d\n", stack_state());
                }
            } while(x != 0);
            break;
        case 2: // FIFO queue with shifts
            do {
                scanf("%d",&n);
                if(n > 0) queue_push(n);
                else {
                    if(n < 0) queue_pop(-n);
                    else queue_state();
                }
            } while(n != 0);
            break;
        case 3: // queue with cyclic buffer
            client_no = 0;
            do {
                scanf("%d",&op_code);
                if(op_code > 0) cbuff_push(++client_no);
                else {
                    if(op_code < 0) cbuff_pop();
                    else cbuff_state();
                }
            } while(op_code != 0);
            break;
        default:
            printf("NOTHING TO DO!\n");
    }
    return 0;
}