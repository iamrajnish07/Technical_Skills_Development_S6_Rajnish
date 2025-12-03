//Question 11: Length of a singly linked list (recursively)
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

int lengthRecursive(Node* head){
    if(!head) return 0;
    return 1 + lengthRecursive(head->next);
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    printf("%d\n", lengthRecursive(head));
    return 0;
}
