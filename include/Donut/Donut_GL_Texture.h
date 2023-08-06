#ifndef Donut_GL_Texture_h
#define Donut_GL_Texture_h

#include "Donut/Donut_GL.h"

class Donut_GL_Texture
{
public:
    Donut_GL_Texture(const unsigned char * data, int width, int height);
    ~Donut_GL_Texture();

private:
    GLuint mId;
};

#endif