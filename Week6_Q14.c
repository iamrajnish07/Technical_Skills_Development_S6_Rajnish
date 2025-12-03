//Question 14: Find Lowest Common Ancestor (LCA) of two nodes in a binary tree
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
int exists(Node* root, int key){ if(!root) return 0; if(root->data==key) return 1; return exists(root->left,key)||exists(root->right,key); }
Node* lca(Node* root, int n1, int n2){
    if(!root) return NULL;
    if(root->data==n1 || root->data==n2) return root;
    Node* l = lca(root->left, n1, n2);
    Node* r = lca(root->right, n1, n2);
    if(l && r) return root;
    return l?l:r;
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    int a,b; if(scanf("%d %d",&a,&b)!=2) return 0;
    Node* res = lca(root,a,b);
    if(res) printf("%d\n", res->data); else printf("-1\n");
    return 0;
}