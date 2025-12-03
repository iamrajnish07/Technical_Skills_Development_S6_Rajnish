//Question 9: Delete a node from a BST
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }
Node* insertBST(Node* root, int x){ if(!root) return newNode(x); if(x < root->data) root->left = insertBST(root->left, x); else root->right = insertBST(root->right, x); return root; }
Node* findMin(Node* root){ while(root && root->left) root = root->left; return root; }
Node* deleteNode(Node* root, int key){
    if(!root) return NULL;
    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(!root->left){ Node* r=root->right; free(root); return r; }
        else if(!root->right){ Node* l=root->left; free(root); return l; }
        Node* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}
void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = NULL;
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); root = insertBST(root, x); }
    int key; if(scanf("%d",&key)!=1) return 0;
    root = deleteNode(root, key);
    inorder(root); printf("\n");
    return 0;
}