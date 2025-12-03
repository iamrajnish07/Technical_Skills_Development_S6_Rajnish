//Question 1: Create and display a singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;

Node* createList(int n) {
    if(n<=0) return NULL;
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        int x; if(scanf("%d",&x)!=1) x=0;
        Node* t = (Node*)malloc(sizeof(Node));
        t->data = x; t->next = NULL;
        if(!head) head = tail = t; else { tail->next = t; tail = t; }
    }
    return head;
}

void display(Node* head){
    Node* p=head;
    while(p){ printf("%d ", p->data); p=p->next; }
    printf("\n");
}

int main(){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    display(head);
    return 0;
}