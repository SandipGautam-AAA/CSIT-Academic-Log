#include <stdio.h>

#define MAX 10

int main()
{
    int n;
    float matrix[MAX][MAX + 1], result[MAX];

    printf("Enter the size of matrix[nxn]: ");
    scanf("%d", &n);

    // Taking Input
    printf("Enter the Augmented Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);   // FIXED
        }
    }

    // Forward Elimination
    for (int k = 0; k < n - 1; k++)
    {
        if (matrix[k][k] == 0.0)
        {
            printf("Zero Pivot Error\n");
            return 1;
        }

        for (int i = k + 1; i < n; i++)
        {
            float factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j <= n; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            result[i] -= matrix[i][j] * result[j];
        }
        result[i] /= matrix[i][i];
    }

    // Output
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %.3f\n", i + 1, result[i]);
    }

    return 0;
}
