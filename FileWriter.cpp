#include "FileWriter.h"
#include <fstream>
#include <stdexcept>

void FileWriter::write(const std::string& filePath, const std::string& content) {
    std::ofstream outFile(filePath, std::ofstream::out);

    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    const std::size_t chunkSize = 128;
    std::size_t pos = 0;

    while (pos < content.length()) {
        std::string chunk = content.substr(pos, chunkSize);
        outFile.write(chunk.c_str(), chunk.size());
        pos += chunkSize;
    }

    outFile.close();
}


