//Question 6: Check whether two binary trees are identical
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }

Node* buildLevelOrderFromArray(int *a, int n){
    if(n<=0) return NULL;
    Node **q = (Node**)malloc(sizeof(Node*)*n);
    int f=0,r=0;
    Node* root=newNode(a[0]); q[r++]=root; int idx=1;
    while(idx<n){
        Node* cur=q[f++];
        if(idx<n){ cur->left=newNode(a[idx++]); q[r++]=cur->left; }
        if(idx<n){ cur->right=newNode(a[idx++]); q[r++]=cur->right; }
    }
    free(q);
    return root;
}

int identical(Node* a, Node* b){
    if(!a && !b) return 1;
    if(!a || !b) return 0;
    if(a->data != b->data) return 0;
    return identical(a->left, b->left) && identical(a->right, b->right);
}

int main(){
    int n1; if(scanf("%d",&n1)!=1) return 0;
    int *a1 = (int*)malloc(sizeof(int)*n1);
    for(int i=0;i<n1;i++) if(scanf("%d",&a1[i])!=1) a1[i]=0;
    int n2; if(scanf("%d",&n2)!=1) return 0;
    int *a2 = (int*)malloc(sizeof(int)*n2);
    for(int i=0;i<n2;i++) if(scanf("%d",&a2[i])!=1) a2[i]=0;
    Node* t1 = buildLevelOrderFromArray(a1, n1);
    Node* t2 = buildLevelOrderFromArray(a2, n2);
    printf("%d\n", identical(t1,t2));
    free(a1); free(a2);
    return 0;
}