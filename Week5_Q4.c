//Question 4: Write a program to reverse an array using a stack
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    if(n<=0){ printf("\n"); return 0; }
    int *a = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int *stack = (int*)malloc(sizeof(int)*n);
    int top = -1;
    for(int i=0;i<n;i++) stack[++top] = a[i];
    for(int i=0;i<n;i++) a[i] = stack[top--];
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    free(a); free(stack);
    return 0;
}