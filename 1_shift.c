#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptShiftCipher(char plainText[], int shift, char encryptedText[])
{
    int i;
    int length = strlen(plainText);

    for (i = 0; i < length; ++i)
    {
        char currentChar = plainText[i];

        // Convert the character to uppercase if it is an alphabet
        if (isalpha(currentChar))
        {
            if (islower(currentChar))
            {
                // Encrypt lowercase letters
                encryptedText[i] = ((currentChar - 'a' + shift) % 26) + 'a';
            }
            else
            {
                // Encrypt uppercase letters
                encryptedText[i] = ((currentChar - 'A' + shift) % 26) + 'A';
            }
        }
        else
        {
            // If the current character is not an alphabet, leave it unchanged
            encryptedText[i] = plainText[i];
        }
    }

    encryptedText[i] = '\0'; // Null-terminate the encrypted text
}

int main()
{
    char plainText[1000], encryptedText[1000];
    int shift;

    printf("Enter the plain text: ");
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = '\0'; // Remove newline character from input

    printf("Enter the shift value (an integer): ");
    scanf("%d", &shift);

    encryptShiftCipher(plainText, shift, encryptedText);

    printf("Encrypted Text: %s\n", encryptedText);
    printf("Suprem Bhatta ROLL_NO:31");

    return 0;
}
