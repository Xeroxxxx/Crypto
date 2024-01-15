#include <stdio.h>
#include <math.h>
#include <windows.h>
// Function to calculate (base^exponent) % mod efficiently
long long modPow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}
int main() {
    // Clear the console screen
    system("cls");
    long long prime, base, privateA, privateB, publicA, publicB, secretA, secretB;
    printf("Enter a prime number (P): ");
    scanf("%lld", &prime);
    printf("Enter a base (G): ");
    scanf("%lld", &base);
    printf("Enter Alice's private key (a): ");
    scanf("%lld", &privateA);
    printf("Enter Bob's private key (b): ");
    scanf("%lld", &privateB);
    // Calculate public keys
    publicA = modPow(base, privateA, prime);
    publicB = modPow(base, privateB, prime);
    // Exchange public keys (In a real-world scenario, this would be done over a secure channel)
    printf("Alice sends her public key to Bob: %lld\n", publicA);
    printf("Bob sends his public key to Alice: %lld\n", publicB);
    // Calculate shared secrets
    secretA = modPow(publicB, privateA, prime);
    secretB = modPow(publicA, privateB, prime);
    printf("Secret key computed by Alice: %lld\n", secretA);
    printf("Secret key computed by Bob: %lld\n", secretB);
    // Verify that the shared secrets are equal (they should be)
    if (secretA == secretB) {
        printf("Shared secret key match!\n");
    } else {
        printf("Shared secrets key do not match. Error in the key exchange.\n");
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
