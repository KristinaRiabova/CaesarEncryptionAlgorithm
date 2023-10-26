#ifndef IREADER_H
#define IREADER_H

#include <string>

class IReader {
public:
    virtual ~IReader() {}
    virtual std::string read(const std::string& filePath) = 0;
};

#endif
