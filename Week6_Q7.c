//Question 7: Insert a node into a Binary Search Tree (BST)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }

Node* insertBST(Node* root, int x){
    if(!root) return newNode(x);
    if(x < root->data) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); root = insertBST(root, x); }
    int val; if(scanf("%d",&val)!=1) return 0;
    root = insertBST(root, val);
    inorder(root); printf("\n");
    return 0;
}