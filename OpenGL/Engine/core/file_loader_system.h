#ifndef FILE_LOADER_SYSTEM_H
#define FILE_LOADER_SYSTEM_H

#include <string>

class FileLoader
{
public:
    static std::string getProjPath();
    void loadPNG(std::string filePath, int &width, int &height, int &channle, unsigned char* &data);
    static void freePNGData(unsigned char* data);
public:
    FileLoader();
    ~FileLoader();
};

#endif
