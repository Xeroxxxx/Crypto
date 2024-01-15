#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// Modular exponentiation function (to compute a^b mod n)
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
// Rabin-Miller primality test
int is_prime_rabin_miller(long long n, int k) {
    if (n <= 1 || n == 4) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    // Find d and r such that n-1 = 2^r * d, where d is odd
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    // Witness loop
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3);
        long long x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1) {
            continue;
        }
        int is_composite = 1;
        for (int j = 0; j < r; j++) {
            x = mod_pow(x, 2, n);
            if (x == n - 1) {
                is_composite = 0;
                break;
            }
        }
        if (is_composite) {
            return 0;
        }
    }
    return 1;
}
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    long long n;
    int k = 20; // Set a fixed value for the number of iterations
    printf("Enter a number to test for primality: ");
    scanf("%lld", &n);
    if (is_prime_rabin_miller(n, k)) {
        printf("%lld is likely prime.\n", n);
    } else {
        printf("%lld is composite.\n", n);
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
