#include <stdio.h>
#include <string.h>

typedef struct {
    int row;
    int col;
} position;

char mat[5][5]; // Global Variable

void generateMatrix(char *key) {
    int flag[26] = {0};
    int x = 0, y = 0;

    for (int i = 0; i < strlen(key); i++) {
        if (key[i] == 'j')
            key[i] = 'i';

        if (flag[key[i] - 'a'] == 0) {
            mat[x][y++] = key[i];
            flag[key[i] - 'a'] = 1;
        }
        if (y == 5)
            x++, y = 0;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == 'j')
            continue;

        if (flag[ch - 'a'] == 0) {
            mat[x][y++] = ch;
            flag[ch - 'a'] = 1;
        }
        if (y == 5)
            x++, y = 0;
    }
}

char *formatMessage(char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == 'j')
            msg[i] = 'i';
    }

    for (int i = 1; i < strlen(msg); i += 2) {
        if (msg[i - 1] == msg[i])
            msg[i] = 'x';
    }

    int len = strlen(msg);
    if (len % 2 != 0) {
        msg[len] = 'x';
        msg[len + 1] = '\0';
    }

    return msg;
}

position getPosition(char c) {
    position defaultPosition = {-1, -1};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (c == mat[i][j]) {
                position p = {i, j};
                return p;
            }
        }
    }

    return defaultPosition;
}

void encrypt(char *message, char *ctext) {
    int len = strlen(message);
    int ctextIndex = 0;

    for (int i = 0; i < len; i += 2) {
        position p1 = getPosition(message[i]);
        position p2 = getPosition(message[i + 1]);
        int x1 = p1.row, y1 = p1.col;
        int x2 = p2.row, y2 = p2.col;

        if (x1 == x2) {
            ctext[ctextIndex++] = mat[x1][(y1 + 1) % 5];
            ctext[ctextIndex++] = mat[x2][(y2 + 1) % 5];
        } else if (y1 == y2) {
            ctext[ctextIndex++] = mat[(x1 + 1) % 5][y1];
            ctext[ctextIndex++] = mat[(x2 + 1) % 5][y2];
        } else {
            ctext[ctextIndex++] = mat[x1][y2];
            ctext[ctextIndex++] = mat[x2][y1];
        }
    }
    ctext[ctextIndex] = '\0';
}

void decrypt(char *ctext, char *ptext) {
    int len = strlen(ctext);
    int ptextIndex = 0;

    for (int i = 0; i < len; i += 2) {
        position p1 = getPosition(ctext[i]);
        position p2 = getPosition(ctext[i + 1]);
        int x1 = p1.row, y1 = p1.col;
        int x2 = p2.row, y2 = p2.col;

        if (x1 == x2) {
            ptext[ptextIndex++] = mat[x1][(y1 + 4) % 5];
            ptext[ptextIndex++] = mat[x2][(y2 + 4) % 5];
        } else if (y1 == y2) {
            ptext[ptextIndex++] = mat[(x1 + 4) % 5][y1];
            ptext[ptextIndex++] = mat[(x2 + 4) % 5][y2];
        } else {
            ptext[ptextIndex++] = mat[x1][y2];
            ptext[ptextIndex++] = mat[x2][y1];
        }
    }
    ptext[ptextIndex] = '\0';
}

int main() {
    char plaintext[100];
    printf("Enter message: ");
    scanf("%s", plaintext);

    char key[100];
    printf("Enter key: ");
    scanf("%s", key);

    generateMatrix(key);

    printf("Key Matrix:\n");
    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 5; j++) {
            printf("%c  ", mat[k][j]);
        }
        printf("\n");
    }

    printf("Actual Message: %s\n", plaintext);

    char fmsg[100];
    strcpy(fmsg, plaintext);
    formatMessage(fmsg);
    printf("Formatted Message: %s\n", fmsg);

    char ciphertext[100];
    encrypt(fmsg, ciphertext);
    printf("Encrypted Message: %s\n", ciphertext);

    char decryptmsg[100];
    decrypt(ciphertext, decryptmsg);
    printf("Decrypted Message: %s\n", decryptmsg);

    printf("Name : Supreme Bhatta\nRoll No : 31\n");
    return 0;
}
