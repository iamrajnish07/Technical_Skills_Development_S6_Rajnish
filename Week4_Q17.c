//Question 17: Remove a loop in a linked list if it exists
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

void removeLoop(Node* head){
    Node *slow=head, *fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    if(!fast || !fast->next) return;
    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ", p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    int pos; if(scanf("%d",&pos)!=1) return 0;
    if(pos>0){
        Node* tail = head;
        while(tail && tail->next) tail = tail->next;
        Node* join = head;
        for(int i=1;i<pos && join;i++) join = join->next;
        if(tail) tail->next = join;
    }
    removeLoop(head);
    display(head);
    return 0;
}
