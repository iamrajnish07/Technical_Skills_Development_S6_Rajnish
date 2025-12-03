//Question 11: Convert infix expression to postfix using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prec(char c){ if(c=='+'||c=='-') return 1; if(c=='*'||c=='/') return 2; if(c=='^') return 3; return 0; }
int isOperator(char c){ return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^'); }
int main(){
    char s[10005]; if(!fgets(s, sizeof(s), stdin)) return 0;
    int n=strlen(s); while(n>0 && (s[n-1]=='\n' || s[n-1]=='\r')) s[--n]=0;
    char *stack = (char*)malloc(n);
    int top=-1;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c==' '||c=='\t') continue;
        if(isalnum(c)) putchar(c);
        else if(c=='(') stack[++top]=c;
        else if(c==')'){ while(top!=-1 && stack[top]!='(') putchar(stack[top--]); if(top!=-1) top--; }
        else if(isOperator(c)){
            while(top!=-1 && isOperator(stack[top]) && ((prec(stack[top])>prec(c)) || (prec(stack[top])==prec(c) && c!='^'))){
                putchar(stack[top--]);
            }
            stack[++top]=c;
        }
    }
    while(top!=-1) putchar(stack[top--]);
    putchar('\n');
    free(stack);
    return 0;
}