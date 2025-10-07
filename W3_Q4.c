#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5};
    
    int n=sizeof(a)/sizeof(a[0]);
     int b[n];
    int j=0;
    for(int i=n-1;i>=0;i--){
    b[j]=a[i];
    j++;}
     for( j=0;j<n;j++)
    printf("%d\n",b[j]);
}