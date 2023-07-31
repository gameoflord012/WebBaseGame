#include "Donut_ShadderSource.h"

#include <string>

Donut_ShaderSource::Donut_ShaderSource(GLuint shaderType)
{
    shader = glCreateShader(shaderType);
    Donut_glCheckError(GL_INVALID_OPERATION);
}

Donut_ShaderSource::~Donut_ShaderSource()
{
    glDeleteShader(getShader());
    Donut_glCheckError(GL_INVALID_OPERATION);
}

bool Donut_ShaderSource::compileShader(const char * shaderSource)
{
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success != GL_TRUE)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        Donut_LogWarning("Shader failed to compile: %s", infoLog);
    }

    Donut_glCheckError(GL_INVALID_OPERATION);

    return success;
}

GLuint Donut_ShaderSource::getShader()
{
    return shader;
}