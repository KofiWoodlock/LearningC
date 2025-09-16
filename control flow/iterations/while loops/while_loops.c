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

    num = INT_MIN;
    char buff[1024] = {0}; 
    itoa(num, buff);
    printf("Num as decimal: %d, Num as string: %s\n", num, buff);

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