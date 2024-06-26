#include <stdio.h>
double lagrange_interp(double x[], double y[], int n, double xi)
{
    double L, P = 1, result = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        P = 1;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                P *= (xi - x[j]) / (x[i] - x[j]); // for i=0; it calculate the first term of polynomial and //for i=1 second
                // term and so on.....
            }
        }
        L = y[i] * P;
        result += L; // add the individual term and append to result.
    }
    return result;
}
int main()
{
    int n, i;
    double xi;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the value to interpolate: ");
    scanf("%lf", &xi);
    double result = lagrange_interp(x, y, n, xi); // function call
    printf("Interpolated value at %f is %f", xi, result);
    return 0;
}