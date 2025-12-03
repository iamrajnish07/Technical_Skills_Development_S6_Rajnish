//Question 9: Check if a given string of parentheses is balanced
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int match(char a, char b){ if(a=='('&&b==')') return 1; if(a=='['&&b==']') return 1; if(a=='{'&&b=='}') return 1; return 0; }
int main(){
    char s[10005]; if(!fgets(s, sizeof(s), stdin)) return 0;
    if(s[0]=='\n'){ if(!fgets(s, sizeof(s), stdin)) return 0; }
    int n = strlen(s); while(n>0 && (s[n-1]=='\n' || s[n-1]=='\r')) s[--n]=0;
    char *stack = (char*)malloc(n);
    int top=-1;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c=='('||c=='['||c=='{') stack[++top]=c;
        else if(c==')'||c==']'||c=='}'){
            if(top==-1 || !match(stack[top], c)){ printf("Not Balanced\n"); free(stack); return 0; }
            top--;
        }
    }
    if(top==-1) printf("Balanced\n"); else printf("Not Balanced\n");
    free(stack);
    return 0;
}