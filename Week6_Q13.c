//Question 13: Zig-zag / spiral order traversal of a binary tree
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
void zigZag(Node* root){
    if(!root) return;
    Node **s1 = (Node**)malloc(sizeof(Node*)*1000);
    Node **s2 = (Node**)malloc(sizeof(Node*)*1000);
    int t1=0, t2=0;
    s1[t1++] = root;
    while(t1>0 || t2>0){
        while(t1>0){
            Node* node = s1[--t1];
            printf("%d ", node->data);
            if(node->left) s2[t2++] = node->left;
            if(node->right) s2[t2++] = node->right;
        }
        while(t2>0){
            Node* node = s2[--t2];
            printf("%d ", node->data);
            if(node->right) s1[t1++] = node->right;
            if(node->left) s1[t1++] = node->left;
        }
    }
    printf("\n");
    free(s1); free(s2);
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    zigZag(root);
    return 0;
}