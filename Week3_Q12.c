#include <stdio.h>
int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    printf("Row-wise sum:\n");
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += a[i][j];
        printf("Row %d = %d\n", i + 1, sum);
    }
    printf("Column-wise sum:\n");
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += a[i][j];
        printf("Column %d = %d\n", j + 1, sum);
    }
    return 0;
}