//Question 15: Print left view and right view of a binary tree
#include <stdio.h>
#include <stdlib.h>

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

void leftView(Node* root){
    if(!root) return;
    Node **q = (Node**)malloc(sizeof(Node*)*1000);
    int f=0,r=0;
    q[r++]=root;
    while(f<r){
        int sz = r - f;
        for(int i=0;i<sz;i++){
            Node* cur = q[f++];
            if(i==0) printf("%d ", cur->data);
            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }
    }
    printf("\n");
    free(q);
}

void rightView(Node* root){
    if(!root) return;
    Node **q = (Node**)malloc(sizeof(Node*)*1000);
    int f=0,r=0;
    q[r++]=root;
    while(f<r){
        int sz = r - f;
        for(int i=0;i<sz;i++){
            Node* cur = q[f++];
            if(i==sz-1) printf("%d ", cur->data);
            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }
    }
    printf("\n");
    free(q);
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    leftView(root);
    rightView(root);
    return 0;
}