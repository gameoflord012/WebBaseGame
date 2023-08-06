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

bool Donut_glCheckErrorAll();
#endif