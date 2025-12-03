//Question 10: Find the minimum and maximum value in a BST
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }
Node* insertBST(Node* root, int x){ if(!root) return newNode(x); if(x < root->data) root->left = insertBST(root->left, x); else root->right = insertBST(root->right, x); return root; }
int findMin(Node* root){ if(!root) return -1; while(root->left) root = root->left; return root->data; }
int findMax(Node* root){ if(!root) return -1; while(root->right) root = root->right; return root->data; }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); root = insertBST(root, x); }
    printf("%d %d\n", findMin(root), findMax(root));
    return 0;
}