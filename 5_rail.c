#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int nrow, ncol;
} RailFence;

int getKey() {
    int key;
    printf("Enter the Key (number of rails): ");
    scanf("%d", &key);
    return key;
}

void getMessage(char *msg) {
    printf("Enter the message: ");
    getchar(); // Consume the newline character left in the buffer
    fgets(msg, 100, stdin);
    strtok(msg, "\n"); // Remove the trailing newline character
}

void encrypt(RailFence *rf, char *msg, int key) {
    rf->nrow = key;
    rf->ncol = strlen(msg);
    char rail_matrix[rf->nrow][rf->ncol];

    for (int i = 0; i < rf->nrow; i++) {
        for (int j = 0; j < rf->ncol; j++) {
            rail_matrix[i][j] = '^';
        }
    }

    bool downward = false;
    int r = 0, c = 0;
    char ciphertext[100];
    int ctextIndex = 0;

    for (int i = 0; i < strlen(msg); i++) {
        if (r == 0 || r == key - 1)
            downward = !downward;

        rail_matrix[r][c++] = msg[i];

        downward ? r++ : r--;
    }

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(msg); j++) {
            if (rail_matrix[i][j] != '^') {
                ciphertext[ctextIndex++] = rail_matrix[i][j];
            }
        }
    }

    ciphertext[ctextIndex] = '\0';
    printf("\nThe Ciphertext is: %s\n", ciphertext);
}

void decrypt(RailFence *rf, char *msg, int key) {
    rf->nrow = key;
    rf->ncol = strlen(msg);
    char rail_matrix[rf->nrow][rf->ncol];
    char plaintext[100];
    int ptextIndex = 0;

    for (int i = 0; i < rf->nrow; i++) {
        for (int j = 0; j < rf->ncol; j++) {
            rail_matrix[i][j] = '^';
        }
    }

    bool downward;
    int r = 0, c = 0;

    for (int i = 0; i < strlen(msg); i++) {
        if (r == 0)
            downward = true;
        if (r == key - 1)
            downward = false;

        rail_matrix[r][c++] = '~';

        downward ? r++ : r--;
    }

    int indx = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < strlen(msg); j++) {
            if (rail_matrix[i][j] == '~' && indx < strlen(msg)) {
                rail_matrix[i][j] = msg[indx++];
            }
        }
    }

    r = 0, c = 0;
    downward = false;

    for (int i = 0; i < strlen(msg); i++) {
        if (r == 0)
            downward = true;
        if (r == key - 1)
            downward = false;

        if (rail_matrix[r][c] != '~') {
            plaintext[ptextIndex++] = rail_matrix[r][c++];
        }

        downward ? r++ : r--;
    }

    plaintext[ptextIndex] = '\0';
    printf("The Plaintext is: %s\n", plaintext);
}

int main() {
    int choice;
    char more;
    RailFence rf;
    int k;
    char m[100];

    printf("\n1 : ENCRYPTION \n2 : DECRYPTION \n3 : EXIT \n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            k = getKey();
            getMessage(m);
            encrypt(&rf, m, k);
            break;

        case 2:
            k = getKey();
            getMessage(m);
            decrypt(&rf, m, k);
            break;

        case 3:
            exit(1);

        default:
            printf("\nINVALID CHOICE!\n");
    }

    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
