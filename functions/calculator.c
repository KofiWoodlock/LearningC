/* Calculator program using Reverse Polish Notation (RPN) to evaluate expressions */

#include <stdio.h>
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

double push(double f);
double pop();
double strtofloat(char s []);
char getop(char s[], int max);
void clear();
int getch();
void ungetch(int c);

int main() {

    int type;
    char s[MAXOP];
    double op2;

    while (type = getop(s, MAXOP) != EOF) {
        switch (type) {
            case NUM:
                push(strtofloat(s));
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
                    printf("ERR! DIVISION BY 0");
                break;
            case '=':
                printf("\t%2.lf\n", push(pop()));
                break;
            case 'c':
                clear();
                break;
            case TOOBIG:
                printf("ERR! Input is too long.\n");
                break;
            default:
                printf("ERR! Unkown input");
                break;
        }
    }

    return 0;
}

/* Pushes f onto the operands stack */
double push(double f) {
    if (sp < MAXVAL) 
        return (operands[sp++] = f);
    else {
        printf("ERR! Stack overflow");
        clear();
        return(0);
    }
}

/* Removes and returns top value of operands stack */
double pop() {
    if (sp > 0)
        return (operands[sp--]);
    else {
        printf("ERR! Stack is empty");
        clear();
        return (0);
    }
}

double strtofloat(char s[]) {

    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

char getop(char s[], int max) {}

/* Clears contents of stack */
void clear() {
    sp = 0;
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