//Question 5: Find the diameter of a binary tree
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

int diameterUtil(Node* r, int *height){
    if(!r){ *height = 0; return 0; }
    int lh=0, rh=0;
    int ld = diameterUtil(r->left, &lh);
    int rd = diameterUtil(r->right, &rh);
    *height = 1 + max(lh, rh);
    return max(max(ld, rd), lh + rh + 1);
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    int h=0;
    int dia = diameterUtil(root, &h);
    printf("%d\n", dia);
    return 0;
}