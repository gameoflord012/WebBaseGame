#include <assert.h>

#include "Donut/Donut_GL.h"
#include "Donut/Donut_Log.h"

bool Donut_glCheckErrorAll()
{
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        switch (error) {
            case GL_INVALID_ENUM:
                Donut_LogError("OpenGL Error: GL_INVALID_ENUM");
                return false;
            case GL_INVALID_VALUE:
                Donut_LogError("OpenGL Error: GL_INVALID_VALUE");
                return false;
            case GL_INVALID_OPERATION:
                Donut_LogError("OpenGL Error: GL_INVALID_OPERATION");
                return false;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                Donut_LogError("OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION");
                return false;
            case GL_OUT_OF_MEMORY:
                Donut_LogError("OpenGL Error: GL_OUT_OF_MEMORY");
                return false;
            case GL_STACK_UNDERFLOW:
                Donut_LogError("OpenGL Error: GL_STACK_UNDERFLOW");\
                return false;
            case GL_STACK_OVERFLOW:
                Donut_LogError("OpenGL Error: GL_STACK_OVERFLOW");\
                return false;
            default:
                Donut_LogError("OpenGL Error: Unknown error (%#x)", error);
                break;
        }
    }

    return true;
}

Donut_GL_Texture Donut_LoadTexture(const char *path)
{
    Donut_GL_Texture texture;

    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *data = stbi_load(path, &texture.width, &texture.height, &texture.nrChannels, 0);

    assert(data);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    Donut_glCheckErrorAll();

    delete[] data;

    return texture;
}