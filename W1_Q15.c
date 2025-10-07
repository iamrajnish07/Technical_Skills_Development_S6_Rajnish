#include <stdio.h>

int main() {
    int num1, num2, temp;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Use Euclidean algorithm with a while loop
    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    // After the loop, num1 contains the GCD
    printf("GCD = %d\n", num1);

    return 0;
}
