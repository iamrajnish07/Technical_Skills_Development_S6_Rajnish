//Question 3: Check for stack overflow and underflow while implementing stack using array
#include <stdio.h>
#include <stdlib.h>

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
    if(isFull(s)){ printf("Overflow on push %d\n", x); return; }
    s->arr[++s->top] = x;
}

void pop(Stack* s){
    if(isEmpty(s)){ printf("Underflow on pop\n"); return; }
    s->top--;
}

void display(Stack* s){
    if(isEmpty(s)){ printf("\n"); return; }
    for(int i=s->top;i>=0;i--) printf("%d ", s->arr[i]);
    printf("\n");
}

int main(){
    int cap; if(scanf("%d",&cap)!=1) return 0;
    if(cap < 1) cap = 1;
    Stack* s = createStack(cap);
    int pushes; if(scanf("%d",&pushes)!=1) { free(s->arr); free(s); return 0; }
    for(int i=0;i<pushes;i++){ int x; scanf("%d",&x); push(s,x); }
    int pops; if(scanf("%d",&pops)!=1) { free(s->arr); free(s); return 0; }
    for(int i=0;i<pops;i++) pop(s);
    display(s);
    free(s->arr); free(s);
    return 0;
}