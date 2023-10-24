#include <iostream>
#include <dlfcn.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <filesystem>
#include "FileReader.h"
#include "FileWriter.h"

int main() {
    std::srand(std::time(0));

    void* handle = dlopen("/Users/kristina_mbp/CLionProjects/CaesarEncryptionAlgorithm/caesar.dylib", RTLD_LAZY);

    if (!handle) {
        std::cerr << "Library not found: " << dlerror() << std::endl;
        return 1;
    }

    char* (*encryptFunction)(const char*, int) = (char* (*)(const char*, int))dlsym(handle, "encrypt");

    if (!encryptFunction) {
        std::cerr << "Encrypt function not found: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    char* (*decryptFunction)(const char*, int) = (char* (*)(const char*, int))dlsym(handle, "decrypt");

    if (!decryptFunction) {
        std::cerr << "Decrypt function not found: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    FileReader reader;
    FileWriter writer;

    std::string content;

    while (true) {
        int mode;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Normal Mode" << std::endl;
        std::cout << "2. Secret Mode" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> mode;

        if (mode == 0) {
            break;
        } else if (mode != 1 && mode != 2) {
            std::cerr << "Invalid choice." << std::endl;
            continue;
        }

        std::cin.ignore();

        std::string inputFilePath;
        std::string outputFilePath;
        int key = 0;

        if (mode == 1) {
            std::string operation;
            std::cout << "Choose the type of operation (encrypt/decrypt): ";
            std::cin >> operation;

            if (operation != "encrypt" && operation != "decrypt") {
                std::cerr << "Invalid operation. Choose 'encrypt' or 'decrypt'." << std::endl;
                continue;
            }

            std::cout << "Enter the input file path: ";
            std::cin >> inputFilePath;
            std::cout << "Enter the output file path: ";
            std:: cin >> outputFilePath;
            std::cout << "Enter the key: ";
            std::cin >> key;

            if (std::filesystem::exists(inputFilePath)) {
                content = reader.read(inputFilePath);
                char* resultText;

                if (operation == "encrypt") {
                    resultText = encryptFunction(content.c_str(), key);
                } else {
                    resultText = decryptFunction(content.c_str(), key);
                }

                writer.write(outputFilePath, resultText);

                std::cout << (operation == "encrypt" ? "Encrypted" : "Decrypted") << " Text written to " << outputFilePath << std::endl;
                delete[] resultText; // Free memory
            } else {
                std::cerr << "Input file does not exist." << std::endl;
            }
        } else if (mode == 2) {
            std::cout << "Enter the input file path: ";
            std::cin >> inputFilePath;
            std::cout << "Enter the output file path: ";
            std::cin >> outputFilePath;

            key = std::rand() % 26;
            std::cout << "Random Key: " << key << std::endl;

            if (std::filesystem::exists(inputFilePath)) {
                content = reader.read(inputFilePath);
                char* resultText = encryptFunction(content.c_str(), key);

                writer.write(outputFilePath, resultText);

                std::cout << "Encrypted Text written to " << outputFilePath << std::endl;
                delete[] resultText; // Free memory
            } else {
                std::cerr << "Input file does not exist." << std::endl;
            }
        }
    }

    dlclose(handle);

    return 0;
}
