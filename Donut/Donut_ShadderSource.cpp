#include "Donut/Donut_ShadderSource.h"

#include <assert.h>
#include <string>

#include "Donut/Donut_Log.h"

Donut_ShaderSource::Donut_ShaderSource(GLuint shaderType)
{
    Donut_glCheckErrorAll();
    shader = glCreateShader(shaderType);
    Donut_glCheckErrorAll();
}

Donut_ShaderSource::~Donut_ShaderSource()
{
    glDeleteShader(getShader());
    Donut_glCheckErrorAll();
}

bool Donut_ShaderSource::compileShader(const char * shaderSource)
{
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    Donut_assert(success != GL_TRUE, {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        Donut_LogError("shader compile fail: %s", &infoLog);
    });

    Donut_glCheckErrorAll();

    return success;
}

GLuint Donut_ShaderSource::getShader()
{
    return shader;
}