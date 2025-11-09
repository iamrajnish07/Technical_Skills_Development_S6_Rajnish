//Week 2. Question 4.
#include <stdio.h>
int main() {
    int n, r = 0, t;
    printf("Enter a number: ");
    scanf("%d", &n);
    t = n;
    while (n != 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    if (r == t)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
