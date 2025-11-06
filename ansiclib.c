#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define BUFSIZE 100

int strtoint(char s[]);
int chartoint(char n);
double strtofloat(char s[]);
int hextoint(char h[]);
int getch(void);
void ungetch(int c);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int main() {

    char string[] = "15.5";
    double result = 0.0;
    result = strtofloat(string);
    printf("String float: \"%s\"\n", string);
    printf("Converted float: %.2f\n", result);
    return 0;
}

/* Converts string s to an integer keeping it's sign */
int strtoint(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ; // Skip whitespace
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++; // Skip sign
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

int chartoint(char n) {
    if (n >= '0' && n <= '9') 
        return n - '0';
    else
        return -1;
}

/* Convert string s to a double-precesion float */
double strtofloat(char s[]) {

    double val, power;
    int i, sign, exp_sign;
    int exponent = 0;

    /* Skip preceding whitespaces */
    while (isspace(s[i]))
        i++;

    /* Get sign */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    /* Parse digits */
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    printf("%lf\n", val);
    return 0;
    }
    /* Check if number is in scientific notation */
    if (tolower(s[i]) == 'e') {
        i++;
    } else {
        return sign * val / power;
    }
    /* Get the sign of the exponent to know whether number is larger or smaller */
    exp_sign = (s[i++] == '-') ? -1 : 1;
    /* Get the integer exponent */
    for (i; isdigit(s[i]); i++) {
        exponent = 10 * exponent + (s[i] - '0'); 
    }
    /* Compute factor */
    double factor = 1.0;
    for (int j = 0; j < exponent; j++)
        factor *= 10.0;

    if (exp_sign > 0)
        return (val / power) * factor;
    else
        return (val / power) / factor;
}

/* Converts a hexadecimal string literal to an integer value */
int hextoint(char h[]) {

    char c;
    int i = 0;
    int sum = 0;
    int val;

    // skip optional hex indicator 0x or 0X
    if (h[0] == '0' && (h[1] == 'x' || h[1] == 'X'))
        i = 2;

    for (; h[i] != '\0'; i++) {
        c = tolower(h[i]); 
        if (isdigit(c))
            val = c - '0';
        else if (c >= 'a' && c <= 'f')
            val = c - 'a' + 10;
        else {
            printf("Error! %c is not a valid hex character\n", c);
            return -1;
        }
        
        // bitwise shift digits 4 left and
        // bitwise OR with next value to insert into first 4 bits
        sum = (sum << 4) | val;
    }
    return sum;
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