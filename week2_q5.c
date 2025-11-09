//Week 2. Question 5.
#include <stdio.h>
int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    int *p = arr;
    for (int i = 0; i < n; i++)
        scanf("%d", p + i);
    int max = *p;
    for (int i = 1; i < n; i++)
        if (*(p + i) > max)
            max = *(p + i);
    printf("Largest = %d\n", max);
    return 0;
}
