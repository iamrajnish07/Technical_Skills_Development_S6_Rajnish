// Write a C program to reverse a number using a while loop.
#include <stdio.h>

int main() {
    int num, reversed = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num != 0) {
        digit = num % 10;              // Extract last digit
        reversed = reversed * 10 + digit; // Append digit to reversed number
        num = num / 10;                // Remove last digit
    }

    printf("Reversed number = %d\n", reversed);

    return 0;
}
