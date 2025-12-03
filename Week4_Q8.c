//Question 8: Reverse a singly linked list (iterative method)
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

Node* reverseIterative(Node* head){
    Node *prev = NULL, *curr = head;
    while(curr){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ",p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    head = reverseIterative(head);
    display(head);
    return 0;
}