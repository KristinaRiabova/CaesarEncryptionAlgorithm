#include <iostream>
#include <cstring>

extern "C" {
char* encrypt(char* rawText, int key) {
    int length = strlen(rawText);
    char* encryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char currentChar = rawText[i];

        if (isupper(currentChar)) {
            encryptedText[i] = 'A' + (currentChar - 'A' + key % 26 + 26) % 26;
        } else if (islower(currentChar)) {
            encryptedText[i] = 'a' + (currentChar - 'a' + key % 26 + 26) % 26;
        } else {
            encryptedText[i] = currentChar;
        }
    }

    encryptedText[length] = '\0';
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    int length = strlen(encryptedText);
    char* decryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char currentChar = encryptedText[i];

        if (isupper(currentChar)) {
            decryptedText[i] = 'A' + (26 + currentChar - 'A' - key % 26) % 26;
        } else if (islower(currentChar)) {
            decryptedText[i] = 'a' + (26 + currentChar - 'a' - key % 26) % 26;
        } else {
            decryptedText[i] = currentChar;
        }
    }

    decryptedText[length] = '\0';
    return decryptedText;
}
}

