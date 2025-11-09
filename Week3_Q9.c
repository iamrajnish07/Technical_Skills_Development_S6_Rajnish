#include <stdio.h>
int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter number of positions to rotate: ");
    scanf("%d", &k);
    k = k % n;
    printf("Rotated array:\n");
    for (int i = k; i < n; i++) printf("%d ", arr[i]);
    for (int i = 0; i < k; i++) printf("%d ", arr[i]);
    return 0;
}