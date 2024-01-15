#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int calculateTotient(int n) {
    int result = 1;
    for (int i = 2; i < n; i++) {
        if (gcd(n, i) == 1) {
            result++;
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n > 0) {
        int totient = calculateTotient(n);
        printf("The totient (Euler's totient function) of %d is: %d\n", n, totient);
    } else {
        printf("Please enter a positive integer.\n");
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
