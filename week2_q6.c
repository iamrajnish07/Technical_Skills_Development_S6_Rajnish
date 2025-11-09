//Week 2. Question 6.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, *p, sum = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);
        sum += *(p + i);
    }
    printf("Sum = %d\n", sum);
    free(p);
    return 0;
}
