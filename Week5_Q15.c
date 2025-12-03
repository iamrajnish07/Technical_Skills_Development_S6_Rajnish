//Question 15: Reverse a string using a stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[10005];
    if(!fgets(s, sizeof(s), stdin)) return 0;
    int n = strlen(s);
    while(n>0 && (s[n-1]=='\n' || s[n-1]=='\r')) s[--n]=0;
    char *stack = (char*)malloc(n);
    int top = -1;
    for(int i=0;i<n;i++) stack[++top]=s[i];
    for(int i=0;i<n;i++) putchar(stack[top--]);
    putchar('\n');
    free(stack);
    return 0;
}
