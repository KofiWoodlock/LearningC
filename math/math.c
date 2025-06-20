// Math functions available in C 

#include <stdio.h>
#include <math.h>

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

    return 0;
}