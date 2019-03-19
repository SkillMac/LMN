#ifndef RASTERIZER_H

#define RASTERIZER_H

// class VBO
// {
//     
// };
// 
// class VAO
// {
//     
// };
// 
// class EBO
// {
//     
// };

#include "glad/glad.h"

class Rasterizer
{
public:
    enum TextureType {
        PNG, JPG, JPEG, WEBP
    };
public:
    Rasterizer();
    ~Rasterizer();
    
    // pos color uvCoord
    void postTextureGeometry();
    unsigned int postTexture(int width, int height, unsigned char* texData, TextureType type=PNG) const;
};

#endif
