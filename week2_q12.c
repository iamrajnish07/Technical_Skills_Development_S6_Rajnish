//Week 2. Question 12.
#include <stdio.h>
struct Student {
    char name[50];
    int marks;
};
int main() {
    int n;
    scanf("%d", &n);
    struct Student s[n];
    for (int i = 0; i < n; i++)
        scanf("%s %d", s[i].name, &s[i].marks);
    int max = 0;
    for (int i = 1; i < n; i++)
        if (s[i].marks > s[max].marks)
            max = i;
    printf("Topper: %s %d\n", s[max].name, s[max].marks);
    return 0;
}
