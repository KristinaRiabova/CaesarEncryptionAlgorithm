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


char* decrypt(char* encryptedText, int key) {
    int length = strlen(encryptedText);
    char* decryptedText = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char currentChar = encryptedText[i];


        if (isupper(currentChar)) {
            decryptedText[i] = 'A' + (26 + currentChar - 'A' - key) % 26;
        }

        else if (islower(currentChar)) {
            decryptedText[i] = 'a' + (26 + currentChar - 'a' - key) % 26;
        }

        else {
            decryptedText[i] = currentChar;
        }
    }

    decryptedText[length] = '\0';
    return decryptedText;
}

int main() {
    int key;
    char input[1000];
    char choice;

    std::cout << "Choose (e)ncryption or (d)ecryption: ";
    std::cin >> choice;

    std::cout << "Enter the encryption/decryption key: ";
    std::cin >> key;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the message: ";
    std::cin.getline(input, sizeof(input));

    char* result;
    if (choice == 'e' || choice == 'E') {

        result = encrypt(input, key);
        std::cout << "Encrypted: " << result << std::endl;
    } else if (choice == 'd' || choice == 'D') {

        result = decrypt(input, key);
        std::cout << "Decrypted: " << result << std::endl;
    } else {
        std::cout << "Invalid choice. Use 'e' for encryption or 'd' for decryption." << std::endl;
    }


    delete[] result;

    return 0;
}




