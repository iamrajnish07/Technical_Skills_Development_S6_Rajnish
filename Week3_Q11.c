#include <stdio.h>
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int first = a[0], second = -1e9;
    for (int i = 1; i < n; i++) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        } else if (a[i] > second && a[i] < first) {
            second = a[i];
        }
    }
    printf("Second largest element: %d\n", second);
    return 0;
}