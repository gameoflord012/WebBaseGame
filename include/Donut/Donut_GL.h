#ifndef DONUT_GL_H
#define DONUT_GL_H

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <memory>

#define Donut_glCheckError(errorEnum) {\
    GLenum error;\
    while((error = glGetError()) != GL_NO_ERROR)\
    {\
        if(error == errorEnum) Donut_LogError("Donut check gl Error failed: %s", #errorEnum);\
    }\
}

struct Donut_GL_Texture
{
    GLuint id;
    int height, width, nrChannels;

    ~Donut_GL_Texture()
    {
        glDeleteTextures(1, &id);
    }
};

bool Donut_glCheckErrorAll();

Donut_GL_Texture Donut_LoadTexture(const char * path);

#endif