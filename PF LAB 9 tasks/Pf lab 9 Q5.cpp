#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipher(char* plaintext, char* key) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    char ciphertext[textLen + 1];

    char extendedKey[textLen + 1];
    for (int i = 0; i < textLen; i++) {
        extendedKey[i] = toupper(key[i % keyLen]);
    }
    extendedKey[textLen] = '\0';

    for (int i = 0; i < textLen; i++) {
        int plainValue, keyValue, cipherValue;

        if (plaintext[i] == ' ') {
            plainValue = 20;
        } else if (isalpha(plaintext[i])) {
            plainValue = toupper(plaintext[i]) - 'A' + 1;
        } else {
            ciphertext[i] = plaintext[i];
            continue;
        }

        keyValue = extendedKey[i] - 'A' + 1;
        cipherValue = (plainValue + keyValue) % 26;

        if (cipherValue == 0) {
            cipherValue = 26;
        }

        ciphertext[i] = cipherValue + 'A' - 1;
    }
    ciphertext[textLen] = '\0';

    printf("Ciphertext: %s\n", ciphertext);
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    vigenereCipher(plaintext, key);

    return 0;
}
