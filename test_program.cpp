#include <iostream>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("/Users/kristina_mbp/CLionProjects/CaesarEncryptionAlgorithm/caesar.dylib", RTLD_LAZY);

    if (!handle) {
        std::cerr << "Library not found: " << dlerror() << std::endl;
        return 1;
    }

    char* (*encrypt)(char*, int) = (char* (*)(char*, int))dlsym(handle, "encrypt");
    char* (*decrypt)(char*, int) = (char* (*)(char*, int))dlsym(handle, "decrypt");

    if (!encrypt || !decrypt) {
        std::cerr << "Functions not found: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    while (true) {
        char inputText[256];
        int key;

        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Encrypt" << std::endl;
        std::cout << "2. Decrypt" << std::endl;
        std::cout << "0. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice != 1 && choice != 2) {
            std::cerr << "Invalid choice." << std::endl;
            continue;
        }

        std::cin.ignore();

        std::cout << "Enter the input message: ";
        std::cin.getline(inputText, sizeof(inputText));

        std::cout << "Enter the key: ";
        std::cin >> key;

        char* resultText;

        if (choice == 1) {
            resultText = encrypt(inputText, key);
            std::cout << "Encrypted Text: " << resultText << std::endl;
        } else {
            resultText = decrypt(inputText, key);
            std::cout << "Decrypted Text: " << resultText << std::endl;
        }
        std::cout << "Choice: " << choice << std::endl;
        std::cout << "Input Text: " << inputText << std::endl;
        std::cout << "Key: " << key << std::endl;
        std::cout << "Result Text: " << resultText << std::endl;
    }

    dlclose(handle);

    return 0;
}


