#include <stdio.h>
#include <math.h>

#define Y1(x) (pow((x),3) - (3*(x) - 1))   // f(x)
#define Y2(x) (pow((x),2) - 3)             // f'(x)

void Newton_Raphson(float x, float e){
    int count = 1;
    float y;

    printf("Iter\tXn\t\tf(Xn)\n");
    printf("-------------------------------------\n");

    do {
        y = x - (Y1(x) / Y2(x));

        printf("%d\t%.6f\t%.6f\n", count, x, Y1(x));

        x = y;
        count++;

        if (Y2(x) == 0) {
            printf("Error: derivative became zero. Method fails.\n");
            return;
        }

    } while (fabs(Y1(x)) > e);

    printf("\nApprox root = %.6f\n", x);
}

int main() {
    Newton_Raphson(2.0, 0.0001);
    return 0;
}
