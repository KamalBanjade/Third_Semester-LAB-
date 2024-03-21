#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return exp(-x) - x;
}

double g(double x)
{
    return exp(-x);
}

int main()
{
    double x0, x, tolerance;
    int Iteration;

    printf("Enter initial guess x0, tolerance, maximum iteration: ");
    scanf("%lf%lf%d", &x0, &tolerance, &Iteration);

    // Print headers
    printf("Iteration\t\t x\t\t f(x)\n");

    for (int i = 0; i < Iteration; i++)
    {
        x = g(x0);
        printf("%d\t\t\t %.6lf\t %.6lf\n", i, x, f(x));
        if (fabs(x - x0) < tolerance)
        {
            printf("Converged to solution x = %.6lf after %d iterations.\n", x, i);
            return 0;
        }
        x0 = x;
    }
    printf("Failed to converge within %d iterations.\n", Iteration);
    return 0;
}
