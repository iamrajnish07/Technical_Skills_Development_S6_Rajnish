//Write a C program to print the multiplication table of a given number using a for loop.
#include<stdio.h>
int main()
{ int n;
printf("give the number to print table:");
scanf("%d",&n);
    int m;
    for(int i=1;i<=10;i++)
    {
        m=n*i;
        printf("%d\n",m);
    }
   
}