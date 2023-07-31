#ifndef DONUT_SHADERSOURCE_H
#define DONUT_SHADERSOURCE_H

#include "Donut.h"
#include <string>

class DONUT_ShaderSource
{
public:
    DONUT_ShaderSource(GLuint shaderType);
    bool compileShader(const char * shaderSource);
    GLuint getShader();

    ~DONUT_ShaderSource();

private:
    GLuint shader;
    char * mShaderSourcestring;
};

#endif