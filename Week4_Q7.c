//Question 7: Delete a node by its value from a singly linked list
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

Node* deleteByValue(Node* head, int val){
    if(!head) return NULL;
    while(head && head->data==val){
        Node* tmp = head; head = head->next; free(tmp);
    }
    if(!head) return NULL;
    Node* p = head;
    while(p->next){
        if(p->next->data==val){
            Node* tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        } else p = p->next;
    }
    return head;
}

void display(Node* head){
    for(Node* p=head;p;p=p->next) printf("%d ",p->data);
    printf("\n");
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* head = createList(n);
    int val; if(scanf("%d",&val)!=1) return 0;
    head = deleteByValue(head,val);
    display(head);
    return 0;
}