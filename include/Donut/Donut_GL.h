#ifndef DONUT_GL_H
#define DONUT_GL_H

#include <GL/glew.h>
#include <stb/stb_image.h>

#define Donut_glCheckError(errorEnum) {\
    GLenum error;\
    while((error = glGetError()) != GL_NO_ERROR)\
    {\
        if(error == errorEnum) Donut_LogError("Donut check gl Error failed: %s", #errorEnum);\
    }\
}
#define Donut_glCallAssign(assign, glcall) { assign=glcall; Donut_glCheckErrorAll(); }
#define Donut_glCall(glcall) { glcall; Donut_glCheckErrorAll(); }

struct Donut_GL_Texture
{
    GLuint id;
    char * data;
    int height, width, nrChannels;
};

bool Donut_glCheckErrorAll();

Donut_GL_Texture Donut_LoadTexture(const char * path);

#endif