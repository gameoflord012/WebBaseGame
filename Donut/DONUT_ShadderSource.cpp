#include "DONUT_ShadderSource.h"

#include <string>

DONUT_ShaderSource::DONUT_ShaderSource(GLuint shaderType)
{
    shader = glCreateShader(shaderType);
    DONUT_glCheckError(GL_INVALID_OPERATION);
}

DONUT_ShaderSource::~DONUT_ShaderSource()
{
    glDeleteShader(getShader());
    DONUT_glCheckError(GL_INVALID_OPERATION);
}

bool DONUT_ShaderSource::compileShader(const char * shaderSource)
{
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(success != GL_TRUE)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        DONUT_LogWarning("Shader failed to compile: %s", infoLog);
    }

    DONUT_glCheckError(GL_INVALID_OPERATION);

    return success;
}

GLuint DONUT_ShaderSource::getShader()
{
    return shader;
}