/* Calculator program using Reverse Polish Notation (RPN) to evaluate expressions */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP 20 /* Maximmum size of operand, operator*/
#define NUM '0' /* Signal that number found */
#define TOOBIG '9' /* Signal that string to too large */
#define MAXVAL 100 /* Max depth of stack */
#define BUFSIZE 100

// External variables 
int sp = 0; /* Stack pointer */
double operands[MAXVAL]; /* Operands stack */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

void push(double f);
double pop();
int getop(char s[]);
int getch();
void ungetch(int c);

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

/* get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    // Skip whitespace
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* Not a number */
    i = 0;
    if (isdigit(c)) /* Collect integer part */
        while (isdigit(s[++i] = c = getch())) 
            ;
    if (c == '.') /* Collect fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUM;
}

/* get a possibly pushed back character */
int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back onto input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}