#include <stdio.h>

int main() {
    int i;

    printf("Numbers from 1 to 100 (excluding multiples of 5):\n");

    // Loop from 1 to 100
    for (i = 1; i <= 100; i++) {
        if (i % 5 == 0) {
            continue; // Skip multiples of 5
        }
        printf("%d ", i);
    }

    return 0;
}
