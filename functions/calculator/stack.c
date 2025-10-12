#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /* Max depth of stack */
int sp = 0; /* Stack pointer */
double operands[MAXVAL]; /* Operands stack */

/* Pushes f onto the operands stack */
void push(double f) {
    if (sp < MAXVAL) {
        operands[sp++] = f;
    }
    else {
        printf("Error! Stack overflow\n");
    }
}

/* Removes and returns top value of operands stack */
double pop() {
    if (sp > 0)
        return (operands[--sp]);
    else {
        printf("Error! Stack is empty\n");
        return 0.0;
    }
}

/* Prints the top element of the stack but does not remove it */
void peek() {
    printf("%.2lf\n", operands[sp]);
}

/* Prints the current contents of the operands stack */
void printstck() {
    int len = sizeof(operands) / sizeof(double);
    printf("[");
    for (int i = 0; i < len; i++)
        printf("%.2lf ", operands[i]);
    printf("]");
    printf("\n");
}