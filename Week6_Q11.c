//Question 11: Check if a given binary tree is a valid BST
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }
Node* buildLevelOrder(int n){
    if(n<=0) return NULL;
    int *a = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) if(scanf("%d",&a[i])!=1) a[i]=0;
    Node **q = (Node**)malloc(sizeof(Node*)*n);
    int f=0,r=0;
    Node* root=newNode(a[0]); q[r++]=root; int idx=1;
    while(idx<n){
        Node* cur=q[f++];
        if(idx<n){ cur->left=newNode(a[idx++]); q[r++]=cur->left; }
        if(idx<n){ cur->right=newNode(a[idx++]); q[r++]=cur->right; }
    }
    free(a); free(q);
    return root;
}
int isBSTUtil(Node* node, long min, long max){ if(!node) return 1; if(node->data <= min || node->data >= max) return 0; return isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data, max); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    printf("%d\n", isBSTUtil(root, LONG_MIN, LONG_MAX));
    return 0;
}