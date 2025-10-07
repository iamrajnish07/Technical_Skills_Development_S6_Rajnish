#include <stdio.h>

int main() {
    int n, i;
    int evenSum = 0, oddSum = 0;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Loop from 1 to n
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenSum += i; // Add to even sum
        } else {
            oddSum += i;  // Add to odd sum
        }
    }

    // Display results
    printf("Sum of even numbers = %d\n", evenSum);
    printf("Sum of odd numbers = %d\n", oddSum);

    return 0;
}
