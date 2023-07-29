#include "DONUT_ShadderSource.h"

DONUT_ShaderSource::DONUT_ShaderSource(GLuint shaderType)
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
}

bool DONUT_ShaderSource::compileShader(const char * shaderSource)
{
    glShaderSource(vertexShader, 1, &shaderSource, NULL);

    bool success;
    char infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        DONUT_LogWarning("Shader failed to compile: %s", infoLog);
    }

    return success;
}