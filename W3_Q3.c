#include<stdio.h>
int main(){
    int n, sum=0, avg=0;
    printf("Enter no of element:");
    scanf("%d",&n);
    int a[n];
    printf("Enter element of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
           max=a[i];
        }

    }
    printf("maximum %d",max);
    int min=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<min)
        {
           min=a[i];
        }

    }
    printf("\nminimum:%d",min);

    return 0;
}