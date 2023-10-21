#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>

class FileWriter {
public:
    void write(const std::string& filePath, const std::string& content);
};

#endif

