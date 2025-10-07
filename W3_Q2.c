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
    for(int i=0;i<n;i++){
       sum = sum+a[i];
    }
    printf("Sum of element of array:%d",sum);
    avg = sum/n;
    printf("\nAvarage of element of array:%d",avg);
    return 0;
}