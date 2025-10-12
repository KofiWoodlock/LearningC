/* Calculator program using Reverse Polish Notation (RPN) to evaluate expressions */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 20 /* Maximmum size of operand, operator*/
#define TOOBIG '9' /* Signal that string to too large */

int main() {

    printf("Reverse polish notation calculator\n");
    printf("\n");

    int type;
    char s[MAXOP];
    double op2;
    double op1;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUM:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error! division by 0\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 == (int)op2 && op1 == (int)op1)
                    push((int)op1 % (int)op2);
                else
                    printf("Error! %% can only take integer operands\n");
                break;
            case '\n':
                printf("\t%.2lf\n", pop());
                break;
            case TOOBIG:
                printf("Error! Input is too long\n");
                break;
            default:
                printf("Error! Unkown input: %s \n", s);
                break;
        }
    }
    return 0;
}