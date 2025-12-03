//Question 17: Implement two stacks in one array efficiently
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int cap;
    int top1;
    int top2;
} TwoStacks;

TwoStacks* create(int n){
    TwoStacks* ts = (TwoStacks*)malloc(sizeof(TwoStacks));
    ts->arr = (int*)malloc(sizeof(int)*n);
    ts->cap = n;
    ts->top1 = -1;
    ts->top2 = n;
    return ts;
}

void push1(TwoStacks* ts, int x){
    if(ts->top1 + 1 == ts->top2) { printf("Overflow\n"); return; }
    ts->arr[++ts->top1] = x;
}
void push2(TwoStacks* ts, int x){
    if(ts->top1 + 1 == ts->top2) { printf("Overflow\n"); return; }
    ts->arr[--ts->top2] = x;
}
int pop1(TwoStacks* ts){
    if(ts->top1==-1){ printf("Underflow\n"); return -1; }
    return ts->arr[ts->top1--];
}
int pop2(TwoStacks* ts){
    if(ts->top2==ts->cap){ printf("Underflow\n"); return -1; }
    return ts->arr[ts->top2++];
}

void display1(TwoStacks* ts){
    if(ts->top1==-1){ printf("\n"); return; }
    for(int i=ts->top1;i>=0;i--) printf("%d ", ts->arr[i]);
    printf("\n");
}
void display2(TwoStacks* ts){
    if(ts->top2==ts->cap){ printf("\n"); return; }
    for(int i=ts->top2;i<ts->cap;i++) printf("%d ", ts->arr[i]);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    TwoStacks* ts = create(n);
    int a; for(int i=0;i<n;i++){ if(scanf("%d",&a)!=1) break; push1(ts,a); }
    int b; if(scanf("%d",&b)!=1) { free(ts->arr); free(ts); return 0; }
    push2(ts,b);
    display1(ts);
    display2(ts);
    free(ts->arr); free(ts);
    return 0;
}
