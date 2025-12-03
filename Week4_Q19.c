//Question 19: Circular linked list and display its elements
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node* next; } Node;

Node* createCircular(int n){
    if(n<=0) return NULL;
    Node *head=NULL, *tail=NULL;
    for(int i=0;i<n;i++){
        int x; if(scanf("%d",&x)!=1) x=0;
        Node* t = (Node*)malloc(sizeof(Node));
        t->data = x; t->next = NULL;
        if(!head) head = tail = t; else { tail->next = t; tail = t; }
    }
    tail->next = head;
    return head;
}

void displayCircular(Node* head){
    if(!head) { printf("\n"); return; }
    Node* p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    } while(p != head);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createCircular(n);
    displayCircular(head);
    return 0;
}
