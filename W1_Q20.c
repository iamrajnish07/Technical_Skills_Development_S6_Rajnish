#include <stdio.h>

int main() {
    int n, i, sum = 0;

    // Input the value of n
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Loop to calculate sum of series
    for (i = 1; i <= n; i++) {
        sum += i; // Add current number to sum
    }

    // Display the result
    printf("Sum of the series 1 + 2 + ... + %d = %d\n", n, sum);

    return 0;
}
