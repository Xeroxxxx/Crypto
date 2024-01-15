#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptVigenere(char plainText[], char keyword[], char encryptedText[]) {
    int i, j;
    int plainTextLength = strlen(plainText);
    int keywordLength = strlen(keyword);

    for (i = 0, j = 0; i < plainTextLength; ++i, ++j) {
        if (j == keywordLength) {
            j = 0; // Repeat the keyword if it is shorter than the plaintext
        }

        char currentChar = plainText[i];
        char keyChar = keyword[j];

        // Convert the characters to uppercase if they are alphabetic
        if (isalpha(currentChar)) {
            if (islower(currentChar)) {
                currentChar = toupper(currentChar);
            }
            if (islower(keyChar)) {
                keyChar = toupper(keyChar);
            }

            // Encrypt the current character using Vigenere cipher formula
            encryptedText[i] = ((currentChar + keyChar - 2 * 'A') % 26) + 'A';
        } else {
            // If the current character is not an alphabet, leave it unchanged
            encryptedText[i] = plainText[i];
        }
    }

    encryptedText[i] = '\0'; // Null-terminate the encrypted text
}

int main() {
    char plainText[1000], keyword[100], encryptedText[1000];

    printf("Enter the plain text: ");
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = '\0';  // Remove newline character from input

    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';  // Remove newline character from input

    encryptVigenere(plainText, keyword, encryptedText);

    printf("Encrypted Text: %s\n", encryptedText);
    printf("Suprem Bhatta ROLL_NO:31");

    return 0;
}
