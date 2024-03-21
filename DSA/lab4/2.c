#include<stdio.h>

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print Fibonacci series up to 'n' terms
void printFibonacciSeries(int n) {
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", fibonacci(i));
    }
    
    printf("\n");
}

int main() {
    int terms;
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &terms);
    
    printFibonacciSeries(terms);

    return 0;
}
