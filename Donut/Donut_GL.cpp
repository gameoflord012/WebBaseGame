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