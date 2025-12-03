//Question 5: Find the middle element of a stack without using extra space
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* topNode = NULL;

void push(int x){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->next = topNode;
    topNode = t;
}

int findMiddle(){
    if(!topNode) return -1;
    Node *slow = topNode, *fast = topNode;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void freeAll(){
    while(topNode){ Node* t = topNode; topNode = topNode->next; free(t); }
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); push(x); }
    int m = findMiddle();
    if(m==-1) printf("Empty\n"); else printf("%d\n", m);
    freeAll();
    return 0;
}