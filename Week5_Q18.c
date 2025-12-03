//Question 18: Find next greater element for each element in an array using stack
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    int *a = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int *res = (int*)malloc(sizeof(int)*n);
    int *stack = (int*)malloc(sizeof(int)*n);
    int top = -1;
    for(int i=n-1;i>=0;i--){
        while(top!=-1 && stack[top] <= a[i]) top--;
        res[i] = (top==-1) ? -1 : stack[top];
        stack[++top] = a[i];
    }
    for(int i=0;i<n;i++) printf("%d ", res[i]);
    printf("\n");
    free(a); free(res); free(stack);
    return 0;
}
