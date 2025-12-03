//Question 13: Evaluate a prefix expression using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isOperator(char c){ return (c=='+'||c=='-'||c=='*'||c=='/'); }
int main(){
    char s[10005];
    if(!fgets(s, sizeof(s), stdin)) return 0;
    int n=strlen(s); while(n>0 && (s[n-1]=='\n' || s[n-1]=='\r')) s[--n]=0;
    int *stack = (int*)malloc(sizeof(int)*10000); int top=-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]==' ') continue;
        if(isOperator(s[i])){
            int a = stack[top--]; int b = stack[top--];
            int res=0;
            if(s[i]=='+') res = a + b;
            else if(s[i]=='-') res = a - b;
            else if(s[i]=='*') res = a * b;
            else if(s[i]=='/') res = a / b;
            stack[++top]=res;
        } else {
            int j=i; while(j>=0 && s[j]!=' ') j--;
            int val = atoi(&s[j+1]);
            stack[++top]=val;
            i = j;
        }
    }
    if(top>=0) printf("%d\n", stack[top]);
    free(stack);
    return 0;
}