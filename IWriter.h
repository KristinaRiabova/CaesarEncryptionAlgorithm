#ifndef IWRITER_H
#define IWRITER_H

#include <string>

class IWriter {
public:
    virtual ~IWriter() {}
    virtual void write(const std::string& filePath, const std::string& content) = 0;
};

#endif
