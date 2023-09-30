#include <iostream>
#include <cstring>

char* encrypt(char* rawText, int key) {
    int length = strlen(rawText);
    char* encryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char currentChar = rawText[i];

        if (isupper(currentChar)) {
            encryptedText[i] = 'A' + (currentChar - 'A' + key) % 26;
        }

        else if (islower(currentChar)) {
            encryptedText[i] = 'a' + (currentChar - 'a' + key) % 26;
        }

        else {
            encryptedText[i] = currentChar;
        }
    }

    encryptedText[length] = '\0';
    return encryptedText;
}

int main() {
    int key;
    char message[1000];

    std::cout << "Enter the encryption key: ";
    std::cin >> key;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the message to encrypt: ";
    std::cin.getline(message, sizeof(message));

    char* encryptedMessage = encrypt(message, key);
    std::cout << "Encrypted: " << encryptedMessage << std::endl;


    delete[] encryptedMessage;

    return 0;
}


