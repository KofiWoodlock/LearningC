// Program that calculates the circumfrence of a circle 
// Circumfrence is defined as pi * diameter 
// the diameter is twice the radius (2r)

#include <stdio.h>
#include <math.h>

int main() {

    const double PI = 3.14159;    
    double radius;
    double diameter;
    double circumfrence; 
    double area;

    // Get radius
    printf("Please enter diameter: ");
    scanf("%lf", &radius);
    diameter = 2 * radius;
    circumfrence = PI * diameter;
    area = PI * radius * radius;
    
    printf("Circumfrence: %lf", circumfrence);
    printf("\nArea: %lf", area);

    return 0;
}