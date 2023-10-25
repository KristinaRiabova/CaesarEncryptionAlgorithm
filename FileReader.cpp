#include "FileReader.h"
#include <fstream>
#include <stdexcept>

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
