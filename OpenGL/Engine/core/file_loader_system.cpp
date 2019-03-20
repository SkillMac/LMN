#include "file_loader_system.h"
#include "stb_image.h"
#include <direct.h>
#include <iostream>

FileLoader::FileLoader()
{
    
}

FileLoader::~FileLoader()
{
    
}

void FileLoader::loadPNG(std::string filePath, int& width, int& height, int& channle, unsigned char* &data)
{
    std::string tmpFilePath = FileLoader::getProjPath() + filePath;
    data = stbi_load(tmpFilePath.c_str(), &width, &height, &channle, 0);
}

void FileLoader::freePNGData(unsigned char* data)
{
    stbi_image_free(data);
}


std::string FileLoader::getProjPath()
{
#ifdef WINDOWS
    char data[_MAX_PATH];
    _getcwd(data, _MAX_PATH);
    return std::string(data);
#endif
}


