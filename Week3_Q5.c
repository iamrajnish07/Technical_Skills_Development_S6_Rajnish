#include <stdio.h>
int main() {
    int n, x, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) printf("Element not found");
    return 0;
}