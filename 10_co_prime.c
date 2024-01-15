#include <stdio.h>
// Function to calculate the GCD using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int num1, num2;
    // Input two numbers from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    // Calculate the GCD of the two numbers
    int greatestCommonDivisor = gcd(num1, num2);
    // Check if the GCD is 1 (numbers are coprime)
    if (greatestCommonDivisor == 1) {
        printf("%d and %d are coprime.\n", num1, num2);
    } else {
        printf("%d and %d are not coprime.\n", num1, num2);
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
