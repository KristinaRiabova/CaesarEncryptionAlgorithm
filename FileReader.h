#ifndef FILEREADER_H
#define FILEREADER_H

#include "IReader.h"

class FileReader : public IReader {
public:
    virtual std::string read(const std::string& filePath) override;
};

#endif


