#include <stdio.h>

int main() {
    int num, original, reversed = 0, digit;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;  // Store original number

    // Reverse the number using while loop
    while (num != 0) {
        digit = num % 10;             // Extract last digit
        reversed = reversed * 10 + digit; // Add digit to reversed number
        num = num / 10;               // Remove last digit
    }

    // Check if palindrome
    if (original == reversed) {
        printf("%d is a palindrome number.\n", original);
    } else {
        printf("%d is not a palindrome number.\n", original);
    }

    return 0;
}
