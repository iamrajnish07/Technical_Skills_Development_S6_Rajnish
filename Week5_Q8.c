//Question 8: Sort a stack in ascending order using only stack operations (no arrays/lists)
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack{ int *arr; int top; int cap; } Stack;
Stack* create(int c){ Stack* s=(Stack*)malloc(sizeof(Stack)); s->arr=(int*)malloc(sizeof(int)*c); s->top=-1; s->cap=c; return s; }
void push(Stack* s,int x){ if(s->top==s->cap-1) return; s->arr[++s->top]=x; }
int pop(Stack* s){ if(s->top==-1) return -1; return s->arr[s->top--]; }
int peek(Stack* s){ if(s->top==-1) return -1; return s->arr[s->top]; }
void sortedInsert(Stack* s, int x){
    if(s->top==-1 || peek(s) <= x){ push(s,x); return; }
    int temp = pop(s);
    sortedInsert(s,x);
    push(s,temp);
}
void sortStack(Stack* s){
    if(s->top==-1) return;
    int x = pop(s);
    sortStack(s);
    sortedInsert(s,x);
}
void display(Stack* s){ for(int i=s->top;i>=0;i--) printf("%d ", s->arr[i]); printf("\n"); }
int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Stack *s=create(n+5);
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); push(s,x); }
    sortStack(s);
    display(s);
    free(s->arr); free(s);
    return 0;
}