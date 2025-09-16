/*
While loops - key code & terms 
- while loop
    - A type of indefinite iteration that continues whilst some condition is true 
- do while loop
    -  Executes a block of code once and then checks whether some condition is true
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void guessTheNum();
void itoa(int n, char s[]);
void itob(int n, char s[], int b);
void inttostr(int n, char s[]);
void inttobin(int n, char s[]);
void inttohex(int n, char s[]);
void inttooct(int n, char s[]);

int main() {
    // Regular while loop
    printf("------ While Loops ------\n");
    int num = 0;
    while (num <= 0) {
        printf("Enter a number!\n");
        scanf("%d", &num);
    }

    guessTheNum();

    num = 0;

    // Do while loop
    printf("------ Do While Loops ------\n");
    do {
        printf("Please enter a number greater than 0: ");
        scanf("%d", &num);
    } while (num <= 0);

    printf("------ Exercises ------\n");
    printf("\n");
    printf("------ Exercise 3-4 ------\n");
    num = INT_MIN;
    char buff[1024] = {0}; 
    itoa(num, buff);
    printf("Num as decimal: %d, Num as string: %s\n", num, buff);

    printf("------ Exercise 3-5 ------\n");
    char res1[1024];
    char res2[1024];
    char res3[1024];
    char res4[1024];
    char res5[1024];
    char res6[1024];

    printf("Test integer -> binary conversion\n");
    itob(33, res1, 2);
    printf("33 (decimal) -> %s (binary) \n", res1);
    itob(-5, res2, 2);
    printf("-5 (decimal) -> %s (binary) \n", res2);
    printf("\n");

    printf("Test integer -> hexadecimal conversion\n");
    itob(495, res3, 16);
    printf("495 (decmimal) -> %s (hex)\n", res3);
    itob(-90, res4, 16);
    printf("-90 (decmimal) -> %s (hex)\n", res4);
    printf("\n");

    printf("Test integer -> octal conversion\n");
    itob(62, res5, 8);
    printf("62 (decimal) -> %s (octal)\n", res5);
    itob(-8, res6, 8);
    printf("-8 (decimal) -> %s (octal)\n", res6);

    return 0;
}

/* Small game where user has to guess the number i am thinking of */
void guessTheNum() {
    int num, guess;

    num = 60;
    printf("Try to guess the number i am thinking of between 1-100!\n");

    while (scanf("%d", &guess) != EOF) {
        if (guess == num) {
            printf("Correct!\n");
            break;
        } else if (guess < num)
            printf("Go higher!\n");
        else
            printf("Go lower!\n");
    }
}

/*
Non functional
onverts integer n to a string
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) // Record sign
        n = -n; // make positive

        Current function breaks when trying to conver signed INT_MIN as
        we cannot convert it to a positive 

    i = 0;
    printf("n: %ld\n", n);
    do {
        s[i++] = n % 10 + '0'; // get next digits 
    } while ((n /= 10) > 0); // remove digit from n
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}
*/

void itoa(int n, char s[]) {
    int i;
    long long num = n;
    int sign = n;

    if (num < 0)
        num = -num;
    
    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}

/* Converts integer n to representation of base b */
void itob(int n, char s[], int b) {
    switch (b) {
        case 2:
            inttobin(n, s);
            break;
        case 8:
            inttooct(n, s);
            break;
        case 10:
            inttostr(n, s);
            break;
        case 16:
            inttohex(n, s);
            break;
        default:
            printf("Error: base %d is not supported.\n", b);
    }    
}

/* Converts int n to a string stored in s */
void inttostr(int n, char s[]) {
    int i = 0;
    int sign = n;

    do {
        int digit = n % 10;
        if (digit < 0) 
            digit = -digit; // handle negative remainder safely
        s[i++] = '0' + digit;
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}

void inttobin(int n, char s[]) {
    if (n == 0) { // special case for 0
        s[0] = '0';
        s[1] = '\0';
        return;
    }

    int i;
    int j = 0;
    int bits = sizeof(n) * CHAR_BIT;

    for (i = bits - 1; i >= 0; i--)
        s[j++] = ((n >> i) & 01) + '0';

    s[j] = '\0';
}

/* Converts integer n to hex format */
void inttohex(int n, char s[]) {
    int i;
    int sign = n;

    i = 0;
    do {
        int digit = n % 16;
        if (digit < 0) 
            digit = -digit; // handle negative remainder safely
        if (digit < 10)
            s[i++] = '0' + digit;
        else if (digit >= 10 && digit <= 16)
            s[i++] = ('A' + digit)-10;
    } while ((n /= 16) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}

/* Converts integer n to hex format */
void inttooct(int n, char s[]) {
    int i;
    int sign = n;

    i = 0;
    do {
        int digit = n % 8;
        if (digit < 0) 
            digit = -digit; // handle negative remainder safely
        s[i++] = digit + '0';
    } while ((n /= 8) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}