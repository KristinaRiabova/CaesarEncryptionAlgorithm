#include "FileReader.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include "IReader.h"
std::string FileReader::read(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("File not found or could not be opened.");
    }

    std::string content;
    const std::size_t chunkSize = 128;
    char buffer[chunkSize];

    while (file.read(buffer, chunkSize)) {
        content.append(buffer, chunkSize);
    }

    content.append(buffer, file.gcount());

    file.close();
    return content;
}
//int main() {

    //IReader* reader = new FileReader();

   // try {

        //std::string filePath = "example.txt";
       //std::string fileContent = reader->read(filePath);
        //std::cout << "File content: " << fileContent << std::endl;
    //} catch (const std::runtime_error& e) {
        //std::cerr << "Error: " << e.what() << std::endl;
   // }

    //delete reader;
    //return 0;
//}