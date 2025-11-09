//Week 2. Question 17.
#include <stdio.h>
int main() {
    char s[100];
    gets(s);
    for (int i = 0; s[i]; i++) {
        int j = i + 1;
        while (s[j]) {
            if (s[j] == s[i]) {
                for (int k = j; s[k]; k++)
                    s[k] = s[k + 1];
            } else j++;
        }
    }
    printf("%s\n", s);
    return 0;
}
