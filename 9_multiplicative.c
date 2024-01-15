#include <stdio.h>
int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int multiplicativeInverse(int a, int modulus) {
    int x, y;
    int gcd = extendedGCD(a, modulus, &x, &y);

    if (gcd != 1) {
        return -1;
    } else {
        return (x % modulus + modulus) % modulus;
    }
}
int main() {
    int a, modulus;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter the modulus: ");
    scanf("%d", &modulus);
    int inverse = multiplicativeInverse(a, modulus);
    if (inverse != -1) {
        printf("The multiplicative inverse of %d modulo %d is: %d\n", a, modulus, inverse);
    } else {
        printf("The multiplicative inverse does not exist for %d modulo %d\n", a, modulus);
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
