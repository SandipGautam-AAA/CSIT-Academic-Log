#include <stdio.h>
#include <math.h>
/*
x^2-x-1 = 0
x^2 = 1+x
x = (1+x)^-1/2
0 = (1+x)^-1/2-x

x = x^2 - 1
*/


int main()
{
    double x0, x1, e;
    int i = 1;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("Enter allowed error: ");
    scanf("%lf", &e);

    printf("\n--------------------------------------------\n");
    printf(" Iter   x_n            x_(n+1)\n");
    printf("--------------------------------------------\n");

    do
    {
        x1 = sqrt(1 + x0);     // g(x) = √(1 + x)

        printf(" %3d   %12.8lf   %12.8lf\n", i, x0, x1);

        if (fabs(x1 - x0) < e)
            break;

        x0 = x1;
        i++;

    } while (i < 50);

    printf("--------------------------------------------\n");
    printf("Root = %.8lf\n", x1);

    return 0;
}
