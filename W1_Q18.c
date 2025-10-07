#include <stdio.h>

int main() {
    int num, count = 0;

    // Input an integer
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Handle negative numbers
    if (num < 0) {
        num = -num;
    }

    // Count digits using while loop
    if (num == 0) {
        count = 1; // Zero has 1 digit
    } else {
        while (num != 0) {
            num = num / 10; // Remove last digit
            count++;         // Increment digit count
        }
    }

    printf("Number of digits = %d\n", count);

    return 0;
}
