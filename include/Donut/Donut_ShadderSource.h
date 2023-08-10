#ifndef DONUT_SHADERSOURCE_H
#define DONUT_SHADERSOURCE_H

#include "Donut/Donut.h"
#include <string>

enum ShaderType
{
    DONUT_VERTEX_SHADER = GL_VERTEX_SHADER,
    DONUT_FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

class Donut_ShaderSource
{
public:
    Donut_ShaderSource(ShaderType shaderType, const char * shaderSourceDir = NULL);
    bool compileShader(const char * shaderSource);
    GLuint getShader() const;

    ~Donut_ShaderSource();

private:
    GLuint shader;
    char * mShaderSourcestring;
};

#endif