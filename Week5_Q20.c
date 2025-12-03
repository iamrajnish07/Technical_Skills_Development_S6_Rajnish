//Question 20: Implement browser forward and backward navigation using two stacks
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { char *url; struct Node* next; } Node;

void push(Node** top, char* url){
    Node* t = (Node*)malloc(sizeof(Node));
    t->url = strdup(url);
    t->next = *top;
    *top = t;
}
char* pop(Node** top){
    if(!*top) return NULL;
    Node* t = *top; char* u = t->url; *top = t->next; free(t); return u;
}
void clearStack(Node** top){
    while(*top){ char* u = pop(top); free(u); }
}

int main(){
    int n; if(scanf("%d",&n)!=1) return 0;
    char buf[10005];
    Node *back = NULL, *forward = NULL;
    char current[10005] = "";
    for(int i=0;i<n;i++){
        int type; scanf("%d",&type);
        if(type==1){
            scanf("%s", buf);
            if(current[0]) push(&back, current);
            strcpy(current, buf);
            while(forward) free(pop(&forward));
        } else if(type==2){
            char* u = pop(&back);
            if(u){ push(&forward, current); strcpy(current, u); free(u); }
        } else if(type==3){
            char* u = pop(&forward);
            if(u){ push(&back, current); strcpy(current, u); free(u); }
        } else if(type==4){
            if(current[0]) printf("%s\n", current); else printf("Empty\n");
        }
    }
    clearStack(&back); clearStack(&forward);
    return 0;
}
