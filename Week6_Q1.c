//Question 1: Implement a binary tree and perform inorder, preorder, and postorder traversal
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x; t->left = t->right = NULL; return t;
}

Node* buildLevelOrder(int n){
    if(n<=0) return NULL;
    int *a = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) if(scanf("%d",&a[i])!=1) a[i]=0;
    Node **queue = (Node**)malloc(sizeof(Node*)*n);
    int front=0, rear=0;
    Node* root = newNode(a[0]);
    queue[rear++] = root;
    int idx = 1;
    while(idx < n){
        Node* cur = queue[front++];
        if(idx < n){
            cur->left = newNode(a[idx++]);
            queue[rear++] = cur->left;
        }
        if(idx < n){
            cur->right = newNode(a[idx++]);
            queue[rear++] = cur->right;
        }
    }
    free(a); free(queue);
    return root;
}

void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
void preorder(Node* r){ if(!r) return; printf("%d ", r->data); preorder(r->left); preorder(r->right); }
void postorder(Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    Node* root = buildLevelOrder(n);
    inorder(root); printf("\n");
    preorder(root); printf("\n");
    postorder(root); printf("\n");
    return 0;
}