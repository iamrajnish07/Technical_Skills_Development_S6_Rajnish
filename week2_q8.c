//Week 2. Question 8.
#include <stdio.h>
#include <string.h>
int main() {
    char s[100];
    gets(s);
    int i = 0, j = strlen(s) - 1, f = 1;
    while (i < j) {
        if (s[i] != s[j]) {
            f = 0;
            break;
        }
        i++; j--;
    }
    if (f)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
