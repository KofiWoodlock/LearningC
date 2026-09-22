/* Temperature Converter from degrees Celcius to Farenheit */

#define LOWER 0.0 /* Minimum temperature */
#define UPPER 300.0 /* Maximum temperature */
#define STEP 20.0 /* Temperature increment */

void temp_conv_for();
void temp_conv_while();

#include <stdio.h>

/* Prints Celcius-Fahrenheit conversion table */
int main() {
    temp_conv_for();
    return 0;
}

void temp_conv_for() {
    float celcius;

    printf("Celcius Fahrenheit (using for loop) \n");
    for (celcius = LOWER; celcius <= UPPER; celcius += STEP) {
        printf("%4.0f    %6.0f\n", celcius, celcius * 9.0/5.0 + 32);
    }
}

void temp_conv_while() {

    float fahr, celcius;

    celcius = LOWER;
    printf("Celcius Fahrenheit (using while loop) \n");
    while (celcius <= UPPER) {
        fahr = (celcius * 9.0/5.0) + 32;
        printf("%4.0f    %6.0f\n", celcius, fahr);
        celcius += STEP;
    }
}

