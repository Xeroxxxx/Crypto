#include <stdio.h>

int main() {
    int n, m = 1, mod;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter the modulus: ");
    scanf("%d", &mod);

    //Bruteforce
    while (((n * m) % mod) != 1) {
        m++;
    }

    printf("The multiplicative inverse is: %d\n", m);
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
