#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "IWriter.h"

class FileWriter : public IWriter {
public:
    virtual void write(const std::string& filePath, const std::string& content) override;
};

#endif
