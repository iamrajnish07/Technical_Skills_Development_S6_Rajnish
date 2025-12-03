//Question 12: Search for a given element in a singly linked list
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

int search(Node* head, int key){
    int pos=1;
    for(Node* p=head;p;p=p->next, pos++){
        if(p->data==key) return pos;
    }
    return -1;
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    int key; if(scanf("%d",&key)!=1) return 0;
    printf("%d\n", search(head,key));
    return 0;
}
