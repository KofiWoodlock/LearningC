/*
Type conversions - key terms & code
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double strtofloat(char s[]);
int strtoint(char s[]);
int hextoint(char h[]);
int chartoint(char n);
double atof(char s[]);

int main() {

    char h[] = "FF";
    int res;
    res = hextoint(h);
    printf("%d", res);
    return 0;

    // char n[] = "15.5";
    // double res = 0;
    
    // res = strtofloat(n);
    // printf("string float: %s\n", n);
    // printf("converted float: %.2lf\n", res);
    // printf("float less 10: %.2lf", res-10);

    // return 0;
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

// /* Convers passed hexadecimal value to an integer */
// int hextoint(char s[]) {

//     int len, i;
//     int sum = 0;
//     int exponent = 0;

//     // Derive input length and convert input to lowercase
//     for (i = 0, len = 0; s[i] != '\0'; i++) {
//         if (isalpha(s[i]))
//             s[i] = tolower(s[i]);
//         len++;
//     } 

//     for (i = len - 1; s[i] != 'x'; i--, exponent++) {
//         // Case of a digit 
//         if (isdigit(s[i]))
//             sum += chartoint(s[i]) * pow(16, exponent);
//         else if (s[i] >= 'a' &&  s[i] <= 'f')
//             sum += ((s[i] - 'a') + 10) * pow(16, exponent);
//         else {
//             printf("Error incorrect hex format");
//             return -1;
//         }
//     }
//     printf("result: %d", sum);
//     return sum;
// }

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

/* Converts string s into it's double precision equivilant */
double atof(char s[]) {
    double val, power;    
    int i, sign;
    
    /* Skip whitespaces */
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + s[i] - '0'; 
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}