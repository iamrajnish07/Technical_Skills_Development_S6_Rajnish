//Question 10: Evaluate a postfix expression using a stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char line[10005];
    if(!fgets(line, sizeof(line), stdin)) return 0;
    int len=strlen(line); while(len>0 && (line[len-1]=='\n' || line[len-1]=='\r')) line[--len]=0;
    char *token = strtok(line, " ");
    int *stack = (int*)malloc(sizeof(int)*10000); int top=-1;
    while(token){
        if(strcmp(token,"+")==0){ int b=stack[top--]; int a=stack[top--]; stack[++top]=a+b; }
        else if(strcmp(token,"-")==0){ int b=stack[top--]; int a=stack[top--]; stack[++top]=a-b; }
        else if(strcmp(token,"*")==0){ int b=stack[top--]; int a=stack[top--]; stack[++top]=a*b; }
        else if(strcmp(token,"/")==0){ int b=stack[top--]; int a=stack[top--]; stack[++top]=a/b; }
        else { stack[++top]=atoi(token); }
        token = strtok(NULL, " ");
    }
    if(top>=0) printf("%d\n", stack[top]);
    free(stack);
    return 0;
}