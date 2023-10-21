#include "FileReader.h"
#include <fstream>
#include <stdexcept>

std::string FileReader::read(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("File not found or could not be opened.");
    }

    std::string content;
    char buffer[128];
    while (!file.eof()) {
        file.read(buffer, sizeof(buffer));
        content.append(buffer, file.gcount());
    }

    file.close();
    return content;
}
