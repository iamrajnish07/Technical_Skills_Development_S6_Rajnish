//Week 2. Question 20.
#include <stdio.h>
int add(int a, int b){return a + b;}
int sub(int a, int b){return a - b;}
int mul(int a, int b){return a * b;}
float divi(int a, int b){return (float)a / b;}
int main() {
    int ch, a, b;
    printf("1.Add 2.Sub 3.Mul 4.Div\n");
    scanf("%d", &ch);
    scanf("%d%d", &a, &b);
    switch (ch) {
        case 1: printf("%d\n", add(a, b)); break;
        case 2: printf("%d\n", sub(a, b)); break;
        case 3: printf("%d\n", mul(a, b)); break;
        case 4: printf("%.2f\n", divi(a, b)); break;
        default: printf("Invalid\n");
    }
    return 0;
}
