#include <stdio.h>

int gcd(int u, int v) {
    int temp;
    while (v != 0) {
        temp = u % v;  // Calculate the remainder of u divided by v
        u = v;         // Assign the value of v to u
        v = temp;      // Assign the remainder to v
    }
    return u;          // When v becomes 0, u contains the GCD
}

int main() {
    int a, b;
    printf("Enter two non-negative integers: ");
    scanf("%d %d", &a, &b);

    int result = gcd(a, b);
    printf("The GCD of %d and %d is %d\n", a, b, result);

    return 0;
}
