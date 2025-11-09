//Week 2. Question 9.
#include <stdio.h>
#include <ctype.h>
int main() {
    char s[200];
    gets(s);
    int v = 0, c = 0, d = 0, sp = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
            else
                c++;
        } else if (isdigit(s[i]))
            d++;
        else
            sp++;
    }
    printf("Vowels=%d Consonants=%d Digits=%d Specials=%d\n", v, c, d, sp);
    return 0;
}
