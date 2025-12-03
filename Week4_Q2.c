//Question 2: Insert a node at the beginning of a singly linked list
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

Node* insertAtBeginning(Node* head, int val){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = val; t->next = head;
    return t;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ",p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    int val; if(scanf("%d",&val)!=1) return 0;
    head = insertAtBeginning(head,val);
    display(head);
    return 0;
}