//Question 19: Design a stack using queues (using two queues)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int cap;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQ(int c){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(sizeof(int)*c);
    q->cap = c; q->front = 0; q->rear = -1; q->size = 0;
    return q;
}
int isEmptyQ(Queue* q){ return q->size==0; }
void enqueue(Queue* q,int x){ if(q->size==q->cap) return; q->rear=(q->rear+1)%q->cap; q->arr[q->rear]=x; q->size++; }
int dequeue(Queue* q){ if(q->size==0) return -1; int v=q->arr[q->front]; q->front=(q->front+1)%q->cap; q->size--; return v; }

typedef struct {
    Queue *q1;
    Queue *q2;
    int cap;
} StackUsingQueues;

StackUsingQueues* createS(int c){
    StackUsingQueues* s = (StackUsingQueues*)malloc(sizeof(StackUsingQueues));
    s->q1 = createQ(c);
    s->q2 = createQ(c);
    s->cap = c;
    return s;
}

void pushS(StackUsingQueues* s, int x){
    enqueue(s->q2, x);
    while(!isEmptyQ(s->q1)) enqueue(s->q2, dequeue(s->q1));
    Queue* tmp = s->q1; s->q1 = s->q2; s->q2 = tmp;
}
int popS(StackUsingQueues* s){
    if(isEmptyQ(s->q1)){ printf("Underflow\n"); return -1; }
    return dequeue(s->q1);
}
int topS(StackUsingQueues* s){
    if(isEmptyQ(s->q1)){ printf("Empty\n"); return -1; }
    return s->q1->arr[s->q1->front];
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    StackUsingQueues* s = createS(n+5);
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); pushS(s,x); }
    int op; if(scanf("%d",&op)!=1) return 0;
    if(op==1) printf("%d\n", topS(s));
    else if(op==2) { int v = popS(s); if(v!=-1) printf("%d\n", v); }
    else if(op==3) { while(!isEmptyQ(s->q1)) { printf("%d ", dequeue(s->q1)); } printf("\n"); }
    return 0;
}
