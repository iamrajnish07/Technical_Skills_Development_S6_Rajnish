//Question 16: Check whether a given number is palindrome using stack
#include <stdio.h>
#include <stdlib.h>

int main(){
    long long x;
    if(scanf("%lld",&x)!=1) return 0;
    if(x<0){ printf("Not Palindrome\n"); return 0; }
    long long t = x;
    char stack[32];
    int top=-1;
    if(t==0) stack[++top]='0';
    while(t>0){ stack[++top] = '0' + (t%10); t/=10; }
    long long y=0;
    while(top!=-1){ y = y*10 + (stack[top--]-'0'); }
    if(y==x) printf("Palindrome\n"); else printf("Not Palindrome\n");
    return 0;
}
