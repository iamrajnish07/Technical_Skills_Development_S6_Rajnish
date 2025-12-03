//Question 1: Implement a stack using an array with operations push(), pop(), peek(), and display()
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAP 1000

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int)*capacity);
    return s;
}

int isFull(Stack* s){ return s->top == s->capacity - 1; }
int isEmpty(Stack* s){ return s->top == -1; }

void push(Stack* s, int x){
    if(isFull(s)){ printf("Overflow\n"); return; }
    s->arr[++s->top] = x;
}

void pop(Stack* s){
    if(isEmpty(s)){ printf("Underflow\n"); return; }
    s->top--;
}

int peek(Stack* s){
    if(isEmpty(s)){ printf("Empty\n"); return -1; }
    return s->arr[s->top];
}

void display(Stack* s){
    if(isEmpty(s)){ printf("\n"); return; }
    for(int i = s->top; i >= 0; --i) printf("%d ", s->arr[i]);
    printf("\n");
}

int main(){
    int cap; if(scanf("%d",&cap)!=1) return 0;
    if(cap < 1) cap = 1;
    Stack* s = createStack(cap);
    int n; if(scanf("%d",&n)!=1) { free(s->arr); free(s); return 0; }
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); if(!isFull(s)) s->arr[++s->top]=x; }
    int cmd; while(scanf("%d",&cmd)==1){
        if(cmd==1){ int v; if(scanf("%d",&v)==1) push(s,v); }
        else if(cmd==2) pop(s);
        else if(cmd==3){ int p = peek(s); if(p!=-1) printf("%d\n", p); }
        else if(cmd==4) display(s);
        else break;
    }
    free(s->arr); free(s);
    return 0;
}