//Question 8: Search a value in a Binary Search Tree (BST)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }
Node* insertBST(Node* root, int x){ if(!root) return newNode(x); if(x < root->data) root->left = insertBST(root->left, x); else root->right = insertBST(root->right, x); return root; }
int searchBST(Node* root, int key){ if(!root) return 0; if(root->data==key) return 1; if(key < root->data) return searchBST(root->left, key); return searchBST(root->right, key); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); root = insertBST(root, x); }
    int key; if(scanf("%d",&key)!=1) return 0;
    printf("%d\n", searchBST(root, key));
    return 0;
}