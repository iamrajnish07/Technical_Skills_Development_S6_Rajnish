//Question 17: Print all root-to-leaf paths of a binary tree
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
void printPathsUtil(Node* node, int path[], int pathLen){
    if(!node) return;
    path[pathLen++] = node->data;
    if(!node->left && !node->right){
        for(int i=0;i<pathLen;i++){ printf("%d ", path[i]); }
        printf("\n");
    } else {
        printPathsUtil(node->left, path, pathLen);
        printPathsUtil(node->right, path, pathLen);
    }
}
void printPaths(Node* root){
    int path[1000];
    printPathsUtil(root, path, 0);
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    printPaths(root);
    return 0;
}