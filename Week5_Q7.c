//Question 7: Copy one stack into another stack without changing the order of elements
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack{ int *arr; int top; int cap; } Stack;
Stack* create(int c){ Stack* s=(Stack*)malloc(sizeof(Stack)); s->arr=(int*)malloc(sizeof(int)*c); s->top=-1; s->cap=c; return s; }
void push(Stack* s,int x){ if(s->top==s->cap-1) return; s->arr[++s->top]=x; }
int pop(Stack* s){ if(s->top==-1) return -1; return s->arr[s->top--]; }
void display(Stack* s){ for(int i=s->top;i>=0;i--) printf("%d ", s->arr[i]); printf("\n"); }
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Stack *s=create(n+5); for(int i=0;i<n;i++){ int x; scanf("%d",&x); push(s,x); }
    Stack *aux=create(n+5); Stack *copy=create(n+5);
    while(s->top!=-1) push(aux, pop(s));
    while(aux->top!=-1){ int v=pop(aux); push(s,v); push(copy,v); }
    display(s);
    display(copy);
    free(s->arr); free(s); free(aux->arr); free(aux); free(copy->arr); free(copy);
    return 0;
}