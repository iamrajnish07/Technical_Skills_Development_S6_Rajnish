#include <stdio.h>
int main() {
    int n1, n2, i, j, temp;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter elements of first array:\n");
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int b[n2];
    printf("Enter elements of second array:\n");
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);
    int n3 = n1 + n2, c[n3];
    for (i = 0; i < n1; i++) c[i] = a[i];
    for (j = 0; j < n2; j++) c[i++] = b[j];
    for (i = 0; i < n3 - 1; i++)
        for (j = 0; j < n3 - i - 1; j++)
            if (c[j] > c[j + 1]) {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
    printf("Merged sorted array:\n");
    for (i = 0; i < n3; i++) printf("%d ", c[i]);
    return 0;
}