#include <stdio.h>
#include <math.h>

#define F(x) (pow((x), 3) - 3*(x) + 1)

void getInputs(double *A, double *B) {
    printf("Enter first guess: ");
    scanf("%lf", A);

    printf("Enter second guess: ");
    scanf("%lf", B);
}

void Bisect(double e) {
    double A, B, C;
    double fA, fB, fC;
    int iter = 0, maxIter = 1000;

    getInputs(&A, &B);

    fA = F(A);
    fB = F(B);

    // Ensure valid interval
    while (fA * fB > 0) {
        printf("Invalid interval! f(A)*f(B) > 0. Enter again.\n");
        getInputs(&A, &B);
        fA = F(A);
        fB = F(B);
    }

    printf("\nIter\tA\t\tF(A)\t\tB\t\tF(B)\t\tC\t\tF(C)\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    while (fabs(B - A) > e && iter < maxIter) {
        C = (A + B) / 2.0;
        fC = F(C);

        printf("%3d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n",
               iter + 1, A, fA, B, fB, C, fC);

        if (fA * fC < 0) {
            B = C;
            fB = fC;
        } else {
            A = C;
            fA = fC;
        }

        if (fC == 0.0)
            break;

        iter++;
    }

    printf("\nFinal root approximation: %.8f\n", (A + B) / 2.0);
    printf("Iterations used: %d\n", iter + 1);
}

int main() {
    Bisect(0.0001);
    return 0;
}
