#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 3) - x - 1;
}

double false_position(double a, double b, double tol, int max_iter) {
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    int iter = 0;

    printf("Iteration\t a\t\t b\t\t c\t\t f(c)\n");

    do {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        printf("%d\t\t %f\t %f\t %f\t", iter, a, b, c);

        if (fc > 0) {
            printf("+ve\n");
        } else if (fc < 0) {
            printf("-ve\n");
        }

        if (fc * fa > 0) {
            a = c;
            fa = fc;
        } else {
            b = c;
            fb = fc;
        }

        iter++;
    } while (fabs(fc) > tol && iter < max_iter);

    return c;
}

int main() {
    double x, y;
    

    printf("Enter the initial guess x: \n");
    scanf("%lf", &x);

    printf("Enter the initial guess y: \n");
    scanf("%lf", &y);

    if (f(x) * f(y) < 0) {
        double root = false_position(x, y, 0.0001, 100);
        printf("The root is: %f\n", root);
    } else {
        printf("Wrong guess, try again.\n");
    }

    return 0;
}

