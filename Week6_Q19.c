//Question 19: Check whether a binary tree is height-balanced (AVL condition)
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

int max(int a,int b){ return a>b?a:b; }
int checkHeight(Node* root){
    if(!root) return 0;
    int lh = checkHeight(root->left);
    if(lh==-1) return -1;
    int rh = checkHeight(root->right);
    if(rh==-1) return -1;
    if(abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}
int isBalanced(Node* root){ return checkHeight(root) != -1; }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    printf("%d\n", isBalanced(root));
    return 0;
}