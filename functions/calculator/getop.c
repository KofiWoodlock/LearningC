#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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
