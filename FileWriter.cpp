#include "FileWriter.h"
#include <fstream>
#include <stdexcept>

void FileWriter::write(const std::string& filePath, const std::string& content) {
    std::ofstream outFile(filePath, std::ios::binary);
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    const std::size_t chunkSize = 128;

    for (std::size_t pos = 0; pos < content.length(); pos += chunkSize) {
        std::string chunk = content.substr(pos, chunkSize);
        outFile.write(chunk.c_str(), chunk.size());
    }

    outFile.close();
}

