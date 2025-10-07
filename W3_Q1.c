#include<stdio.h>
int main(){
    int n;
    printf("Enter no of element:");
    scanf("%d",&n);
    int a[n];
    
    printf("Enter element of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Element of array is:");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}