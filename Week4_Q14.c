//Question 14: Merge two sorted singly linked lists into one sorted list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;

Node* createList(int n){
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        int x; if(scanf("%d",&x)!=1) x=0;
        Node* t = (Node*)malloc(sizeof(Node));
        t->data = x; t->next = NULL;
        if(!head) head = tail = t; else { tail->next = t; tail = t; }
    }
    return head;
}

Node* mergeSorted(Node* a, Node* b){
    Node dummy; Node* tail = &dummy; tail->next = NULL;
    while(a && b){
        if(a->data <= b->data){
            tail->next = a; a = a->next;
        } else {
            tail->next = b; b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ", p->data);
    printf("\n");
}

int main(){
    int n1; if(scanf("%d",&n1)!=1) return 0;
    Node* a = createList(n1);
    int n2; if(scanf("%d",&n2)!=1) return 0;
    Node* b = createList(n2);
    Node* merged = mergeSorted(a,b);
    display(merged);
    return 0;
}
