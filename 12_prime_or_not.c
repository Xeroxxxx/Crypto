#include <stdio.h>
int main() {
    int i, num, count = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        printf("The number is prime.\n");
    } else {
        printf("The number is composite.\n");
    }
    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
