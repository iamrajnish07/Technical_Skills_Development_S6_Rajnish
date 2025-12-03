//Question 18: Doubly linked list with insert at beginning, at end, and at a specific position
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode { int data; struct DNode* prev; struct DNode* next; } DNode;

DNode* createList(int n){
    DNode *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        int x; if(scanf("%d",&x)!=1) x=0;
        DNode* t = (DNode*)malloc(sizeof(DNode));
        t->data = x; t->prev = t->next = NULL;
        if(!head) head = tail = t; else { tail->next = t; t->prev = tail; tail = t; }
    }
    return head;
}

DNode* insertAtBegin(DNode* head, int val){
    DNode* t = (DNode*)malloc(sizeof(DNode));
    t->data = val; t->prev = NULL; t->next = head;
    if(head) head->prev = t;
    return t;
}

DNode* insertAtEnd(DNode* head, int val){
    DNode* t = (DNode*)malloc(sizeof(DNode));
    t->data = val; t->prev = t->next = NULL;
    if(!head) return t;
    DNode* p = head;
    while(p->next) p = p->next;
    p->next = t; t->prev = p;
    return head;
}

DNode* insertAtPos(DNode* head, int pos, int val){
    if(pos<=1) return insertAtBegin(head,val);
    DNode* p = head;
    for(int i=1;i<pos-1 && p;i++) p = p->next;
    if(!p) return insertAtEnd(head,val);
    DNode* t = (DNode*)malloc(sizeof(DNode));
    t->data = val; t->next = p->next; t->prev = p;
    if(p->next) p->next->prev = t;
    p->next = t;
    return head;
}

void display(DNode* head){
    for(DNode* p=head;p;p=p->next) printf("%d ", p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    DNode* head = createList(n);
    int v1; if(scanf("%d",&v1)!=1) return 0;
    head = insertAtBegin(head, v1);
    int v2; if(scanf("%d",&v2)!=1) return 0;
    head = insertAtEnd(head, v2);
    int pos,val; if(scanf("%d %d",&pos,&val)!=2) return 0;
    head = insertAtPos(head,pos,val);
    display(head);
    return 0;
}
