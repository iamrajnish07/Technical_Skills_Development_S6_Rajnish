//Question 2: Implement a stack using linked list with all standard stack operations
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* topNode = NULL;

void push(int x){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = topNode;
    topNode = t;
}
void pop(){
    if(!topNode){ printf("Underflow\n"); return; }
    Node* t = topNode;
    topNode = topNode->next;
    free(t);
}
int peek(){
    if(!topNode){ printf("Empty\n"); return -1; }
    return topNode->data;
}
void display(){
    Node* p = topNode;
    while(p){ printf("%d ", p->data); p = p->next; }
    printf("\n");
}

void freeAll(){
    while(topNode) pop();
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); push(x); }
    int cmd; while(scanf("%d",&cmd)==1){
        if(cmd==1){ int v; if(scanf("%d",&v)==1) push(v); }
        else if(cmd==2) pop();
        else if(cmd==3){ int p = peek(); if(p!=-1) printf("%d\n", p); }
        else if(cmd==4) display();
        else break;
    }
    freeAll();
    return 0;
}