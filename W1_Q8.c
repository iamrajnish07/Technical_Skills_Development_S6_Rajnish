// Write a C program to calculate factorial of a number using a while loop. 
#include<stdio.h>
int main(){
    int n,fact=1;
    printf("Enter a number");
    scanf("%d",&n);
    for(int i=n;i>=1;i--){
        fact=fact*i;
    }
    printf("Factorial of %d is %d:",n,fact);
    return 0;
}