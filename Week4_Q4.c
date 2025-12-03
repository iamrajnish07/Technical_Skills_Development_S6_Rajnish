//Question 4: Insert a node at a specific position in a singly linked list
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

Node* insertAtPosition(Node* head, int pos, int val){
    if(pos<=1){
        Node* t = (Node*)malloc(sizeof(Node));
        t->data=val; t->next=head; return t;
    }
    Node* p = head;
    for(int i=1;i<pos-1 && p;i++) p = p->next;
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = val;
    if(!p){ t->next = NULL; return head ? head : t; }
    t->next = p->next; p->next = t;
    return head;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ",p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    int pos,val; if(scanf("%d %d",&pos,&val)!=2) return 0;
    head = insertAtPosition(head,pos,val);
    display(head);
    return 0;
}