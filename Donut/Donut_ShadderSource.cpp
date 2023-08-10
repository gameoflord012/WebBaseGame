#include "Donut/Donut_ShadderSource.h"
#include "Donut/Utils.h"

#include <assert.h>
#include <string>

#include "Donut/Donut_Log.h"

Donut_ShaderSource::Donut_ShaderSource(ShaderType shaderType, const char * shaderSourcePath)
{
    Donut_glCheckErrorAll();
    shader = glCreateShader(shaderType);
    compileShader(Donut_readfile(Donut_getPath(DONUT_SHADERS_DIR, shaderSourcePath)).c_str());
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

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    Donut_assert(success == GL_TRUE, {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        Donut_LogError("shader compile fail: %s", infoLog);
    });

    Donut_glCheckErrorAll();

    return success;
}

GLuint Donut_ShaderSource::getShader() const
{
    return shader;
}