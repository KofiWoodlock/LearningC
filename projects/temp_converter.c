/*
Program to convert temperature from farhenheit to celcius
*/


#include <stdio.h>

int main() {
    // Variables & constants 
    float fahr;

    printf("Fahrenheit to Celcius converter\n");    
    printf("-------------------------------\n");
    printf("Please enter a temperature in fahrenheit:\n");
    scanf("%f", &fahr);
    
    printf("%1.f fahrenheit: %1.f celcius", fahr, (5.0/9.0) * (fahr-32));

    return 0;
}