#include "FileWriter.h"
#include <fstream>
#include <stdexcept>

void FileWriter::write(const std::string& filePath, const std::string& content) {
    std::ifstream file(filePath);
    if (file.good()) {
        throw std::runtime_error("File already exists. Cannot overwrite.");
    }

    std::ofstream outFile(filePath);
    outFile << content;
    outFile.close();
}

