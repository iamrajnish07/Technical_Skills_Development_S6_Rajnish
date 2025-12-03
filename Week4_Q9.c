//Question 9: Reverse a singly linked list using recursion
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;

Node* createList(int n){
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        int x; if(scanf("%d",&x)!=1) x=0;
        Node* t = (Node*)malloc(sizeof(Node));
        t->data=x; t->next=NULL;
        if(!head) head=tail=t; else { tail->next = t; tail = t; }
    }
    return head;
}

Node* reverseRecursive(Node* head){
    if(!head || !head->next) return head;
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ",p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    head = reverseRecursive(head);
    display(head);
    return 0;
}