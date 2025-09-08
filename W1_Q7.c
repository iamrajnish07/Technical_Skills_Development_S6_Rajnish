// // Write a C program to check w   hether a number is prime using a for loop. 
#include<stdio.h>
int main()
{
    int n,c=1;
    printf("enter the number:");
    scanf("%d",&n);
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            c=0;
            break;
        }
    }
        if(c==1)
        {
            printf("prime");
        }
        else{
            printf("not prime");
        }
   return 0;
    }
    
