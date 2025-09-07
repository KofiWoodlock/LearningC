/*
Type conversions - key terms & code
*/

#include <stdio.h>
#include <ctype.h>

double strtofloat(char s[]);

int main() {

    char n[] = "15.5";
    double res = 0;
    
    res = strtofloat(n);
    printf("string float: %s\n", n);
    printf("converted float: %.2lf\n", res);
    printf("float less 10: %.2lf", res-10);

    return 0;
}

/* Convert string s to a double-precesion float */
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