//Question 6: Implement a stack that returns minimum element in O(1) time (use an auxiliary stack)
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{ int *arr; int top; int cap; } Stack;
Stack* create(int c){ Stack* s=(Stack*)malloc(sizeof(Stack)); s->arr=(int*)malloc(sizeof(int)*c); s->top=-1; s->cap=c; return s; }
void push(Stack* s,int x){ if(s->top==s->cap-1) return; s->arr[++s->top]=x; }
int pop(Stack* s){ if(s->top==-1) return -1; return s->arr[s->top--]; }
int peek(Stack* s){ if(s->top==-1) return -1; return s->arr[s->top]; }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Stack *s=create(n+5); Stack *minst=create(n+5);
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); push(s,x); if(minst->top==-1 || x<=peek(minst)) push(minst,x); }
    int q; if(scanf("%d",&q)!=1) return 0;
    if(q==1){ int m = peek(minst); if(m==-1) printf("Empty\n"); else printf("%d\n", m); }
    else if(q==2){ int v = pop(s); if(v==-1) printf("Underflow\n"); else { if(v==peek(minst)) pop(minst); } int mm = peek(minst); if(mm==-1) printf("Empty\n"); else printf("%d\n", mm); }
    free(s->arr); free(s); free(minst->arr); free(minst);
    return 0;
}