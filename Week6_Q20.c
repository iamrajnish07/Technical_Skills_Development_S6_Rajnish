//Question 20: Find the maximum path sum in a binary tree
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

int max(int a,int b){ return a>b?a:b; }

int maxPathSumUtil(Node* root, int *res){
    if(!root) return 0;
    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);
    int single = max(max(ls, rs) + root->data, root->data);
    int top = max(single, ls + rs + root->data);
    if(top > *res) *res = top;
    return single;
}

int maxPathSum(Node* root){
    int res = INT_MIN;
    maxPathSumUtil(root, &res);
    return res;
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    printf("%d\n", maxPathSum(root));
    return 0;
}