#include <stdio.h>
void xEuclidean(int a, int b, int *gcd, int *x_value, int *y_value) {
    int old_x = 1, x = 0;
    int old_y = 0, y = 1;
    int q, r;
    while (b != 0) {
        q = a / b;    // quotient
        r = a % b;    // remainder
        int temp = x;
        x = old_x - q * x;
        old_x = temp;
        temp = y;
        y = old_y - q * y;
        old_y = temp;
        a = b;
        b = r;
    }
    *x_value = old_x;
    *y_value = old_y;
    *gcd = a;
}
int main() {
    int a, b, x, y, gcd;
    printf("\nEnter the values of 'a' and 'b' for ax + by = gcd(a, b): ");
    scanf("%d %d", &a, &b);
    xEuclidean(a, b, &gcd, &x, &y);
    printf("\nGCD = %d\t x = %d\t and y = %d\n", gcd, x, y);
    if (gcd == 1) {
        printf("%d is the multiplicative inverse of %d\n", x, a);
    } else {
        printf("No multiplicative inverse exists for %d\n", a);
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
