#ifndef Donut_GL_Texture_h
#define Donut_GL_Texture_h

#include "Donut/Donut_GL.h"

enum Donut_TextureChannel
{
    DONUT_RGB = 3,
    DONUT_RGBA = 4,
};

class Donut_GL_Texture
{
public:
    Donut_GL_Texture(const unsigned char * data, int width, int height, unsigned int textureChannel);
    GLuint getId() const;
    ~Donut_GL_Texture();

private:
    GLuint mId;
};

#endif