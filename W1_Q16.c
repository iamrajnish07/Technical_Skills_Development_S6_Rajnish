#include <stdio.h>

int main() {
    int i, j, space, rows;

    // Input number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop for rows
    for (i = 1; i <= rows; i++) {
        // Inner loop for spaces
        for (space = i; space < rows; space++) {
            printf(" ");
        }
        // Inner loop for stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
