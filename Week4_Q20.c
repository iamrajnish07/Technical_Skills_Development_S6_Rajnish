//Question 20: Split a circular linked list into two halves
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

void splitCircular(Node* head, Node** head1, Node** head2){
    if(!head){ *head1 = *head2 = NULL; return; }
    Node *slow = head, *fast = head;
    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next->next == head) fast = fast->next;
    *head1 = head;
    *head2 = slow->next;
    fast->next = slow->next;
    slow->next = head;
}

void displayCircular(Node* head){
    if(!head){ printf("\n"); return; }
    Node* p = head;
    do{ printf("%d ", p->data); p = p->next; } while(p != head);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createCircular(n);
    Node *h1=NULL, *h2=NULL;
    splitCircular(head, &h1, &h2);
    displayCircular(h1);
    displayCircular(h2);
    return 0;
}
