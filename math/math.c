// Math functions available in C 

#include <stdio.h>
#include <math.h>
#include <complex.h>

/* In C99 complex number types were introduced and came in three flavours. That is
float _Complex 
double _Complex
long double _Complex
However complex.h includes macros to make using these types easier - "complex" expands to _Complex
meaning a variable double complex z expands to double _Complex z
See the complexType() function for more information
*/

double computePi(double width);
void complexType();
void printComplex(complex double z);

int main() {
    // Square root function 
    double A = sqrt(81);
    double P = pow(2, 8);
    int R = round(3.14);
    int C = ceil(3.14);
    int F = floor(3.99);
    double abs = fabs(-100);
    double L = log(64);
    // Triganometry 
    double S = sin(30);
    double CO = cos(45);
    double T = tan(90);
    
    printf("\n%lf", A);
    printf("\n%lf", P);
    printf("\n%d", R);
    printf("\n%d", C);

    // Approximating Pi
    printf("\nComputing Pi");
    printf("\n%lf", computePi(0.000001));

    printf("---- Using Complex Numbers ----\n");
    complexType();

    return 0;
}

double computePi(double width) {
    double res = 0;
    for (double i = 0; i <= 1; i+=width) {
        res += (4 / (1 + i * i)) * width;
    }
    return res;
}

void complexType() {
    /* complex.h includes built-in functions to work with complex numbers */
    complex double z = 3.0 + 2.0*I;
    complex double w = 2.0 + 4.0*I;

    /* creal(z) and cimag(z) return the real and imaginary component of a complex
    number respectively*/
    printf("Re(z) = %.2f\n", creal(z));
    printf("Im(z) = %.2f\n", cimag(z));

    /*carg(z) return the argument of a complex number; recall the argument is 
    the angle the vector representing the complex number makes anticlockwise from
    the postive real axis*/
    printf("arg(z) = %.3f\n", carg(z));
    /* cabs(z) returns the modulus of a complex number; recall the modulus is the
    magnitude of the vector representing the complex number and it is computed using
    Pythagoras' Theorem */
    printf("cabs(z) = %.3f\n", cabs(z));

    /* Note: we cannot print complex types natively with printf */
    printComplex(cpow(z, 2));
}

/* Prints a complex number in a + bi format - no newline */
void printComplex(complex double z) {
    double re = creal(z);
    double im = cimag(z);
    if (im > 0) {
        printf("%g+%gi", re, im);    
        return;
    }
    printf("%g%gi", re, im);    
    return;
}