//Question 14: Remove adjacent duplicate characters in a string using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[10005];
    if(!fgets(s, sizeof(s), stdin)) return 0;
    int n = strlen(s);
    while(n>0 && (s[n-1]=='\n' || s[n-1]=='\r')) s[--n]=0;
    char *stack = (char*)malloc(n+1);
    int top = -1;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(top!=-1 && stack[top]==c) top--;
        else stack[++top]=c;
    }
    if(top==-1) printf("\n");
    else{
        for(int i=0;i<=top;i++) putchar(stack[i]);
        putchar('\n');
    }
    free(stack);
    return 0;
}
