//Question 18: Construct a binary tree from inorder and preorder traversal
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;
Node* newNode(int x){ Node* t=(Node*)malloc(sizeof(Node)); t->data=x; t->left=t->right=NULL; return t; }

int searchIndex(int arr[], int start, int end, int val){
    for(int i=start;i<=end;i++) if(arr[i]==val) return i;
    return -1;
}

Node* buildFromPreIn(int pre[], int in[], int inStart, int inEnd, int *preIndex){
    if(inStart > inEnd) return NULL;
    int rootVal = pre[(*preIndex)++];
    Node* root = newNode(rootVal);
    if(inStart == inEnd) return root;
    int inIndex = searchIndex(in, inStart, inEnd, rootVal);
    root->left = buildFromPreIn(pre, in, inStart, inIndex-1, preIndex);
    root->right = buildFromPreIn(pre, in, inIndex+1, inEnd, preIndex);
    return root;
}

void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    int *pre = (int*)malloc(sizeof(int)*n);
    int *in = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    int preIndex = 0;
    Node* root = buildFromPreIn(pre, in, 0, n-1, &preIndex);
    inorder(root); printf("\n");
    free(pre); free(in);
    return 0;
}