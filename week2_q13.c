//Week 2. Question 13.
#include <stdio.h>
struct Complex {
    float r, i;
};
struct Complex add(struct Complex a, struct Complex b) {
    struct Complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;
    return c;
}
int main() {
    struct Complex x, y, z;
    scanf("%f%f", &x.r, &x.i);
    scanf("%f%f", &y.r, &y.i);
    z = add(x, y);
    printf("%.1f + %.1fi\n", z.r, z.i);
    return 0;
}
