#include <stdio.h>
#include <math.h>

#define F(x) (pow((x),3) - (3*(x)) + 1)

void Secant(float x, float y, float e){
    int count = 1;

    printf("Iter\t   Xn-1\t\t   Xn\t\t   Xn+1\n");
    printf("--------------------------------------------------------\n");

    while (fabs(x - y) > e) {

        float z = y - (F(y) * (y - x)) / (F(y) - F(x));

        printf("%d\t %.6f\t %.6f\t %.6f\n", count, x, y, z);

        x = y;
        y = z;
        count++;

        if (F(y) == F(x)) {
            printf("Division by zero encountered! Method fails.\n");
            return;
        }
    }

    printf("\nApprox root = %.6f\n", y);
}

int main(){
    Secant(0, 1, 0.001);
    return 0;
}
