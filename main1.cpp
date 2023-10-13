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
        std::cerr << "Function not found: " << dlerror() << std::endl;
        return 1;
    }

    char* originalText = "Roses are red, violets are blue";
    int key = 1;

    char* encryptedText = encrypt(originalText, key);
    char* decryptedText = decrypt(encryptedText, key);

    std::cout << "Original: " << originalText << std::endl;
    std::cout << "Encrypted: " << encryptedText << std::endl;
    std::cout << "Decrypted: " << decryptedText << std::endl;

    dlclose(handle);

    return 0;
}
