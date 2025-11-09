#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n], dup = 0;
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Duplicate elements are:\n");
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                dup = 1;
                break;
            }
    if (!dup) printf("No duplicates found");
    return 0;
}