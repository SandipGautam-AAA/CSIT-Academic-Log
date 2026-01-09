//1. Define a structure  to read two complex numbers and perform addition,
// subtraction of these two complex numbers and display the result.


#include<stdio.h>

struct complex{
    int real;
    int img;
}c1, c2;

int main() {
    printf("Enter the first complex number(Real,Imaginary): ");
    scanf("%d%d", &c1.real, &c1.img);
    
    printf("Enter the Second complex number(Real, Imaginary ): ");
    scanf("%d%d", &c2.real, &c2.img);

    printf("First = %d + %di\n", c1.real, c1.img);
    printf("Second = %d + %di\n", c2.real, c2.img);

    printf("Sum = %d + %di\n", c1.real + c2.real, c2.img + c1.img );
    printf("Difference = %d + (%di)", c1.real - c2.real, c1.img - c2.img );


    return 0;
}