
#include "rasterizer.h"

Rasterizer::Rasterizer()
{
    
}

Rasterizer::~Rasterizer()
{
    
}

void Rasterizer::postTextureGeometry()
{
    
}


unsigned int Rasterizer::postTexture(int width, int height, unsigned char* texData, TextureType type) const
{
    unsigned int texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    
    // config texture wrap type
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    if(type == PNG)
    {
        glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
        glGenerateTextureMipmap(GL_TEXTURE_2D);
    } else if(type == JPG)
    {
        glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
        glGenerateTextureMipmap(GL_TEXTURE_2D);
    } else if(type == JPEG)
    {
        //TODO
        
    } else if(type == WEBP)
    {
        //TODO
    }
    
    return texId;
}

