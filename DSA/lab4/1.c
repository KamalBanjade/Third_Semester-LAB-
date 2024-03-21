//factorial using recursion
#include<stdio.h>
int factorial(int n){
    if (n==0)
    {
        return 1;
    }
    else return n*factorial(n-1);
     
}
int main(){
    int a;
    printf("Enter the number whose factorial you wanna calculate: ");
    scanf("%d",&a);
    int result = factorial(a);
    printf("The factorial of %d is %d",a,result);
    return 0;
}