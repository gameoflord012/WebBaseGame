#ifndef DONUT_SHADERSOURCE_H
#define DONUT_SHADERSOURCE_H

#include "Donut/Donut.h"
#include <string>

class Donut_ShaderSource
{
public:
    Donut_ShaderSource(GLuint shaderType);
    bool compileShader(const char * shaderSource);
    GLuint getShader();

    ~Donut_ShaderSource();

private:
    GLuint shader;
    char * mShaderSourcestring;
};

#endif