#ifndef DONUT_GL_H
#define DONUT_GL_H

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <memory>

#include "Donut/Donut_Log.h"

#define Donut_glCheckErrorAll() \
{ \
    GLenum error; \
    while ((error = glGetError()) != GL_NO_ERROR) { \
        Donut_LogExtra(); \
        switch (error) { \
            case GL_INVALID_ENUM: \
                Donut_LogError("OpenGL Error: GL_INVALID_ENUM"); \
                break; \
            case GL_INVALID_VALUE: \
                Donut_LogError("OpenGL Error: GL_INVALID_VALUE"); \
                break; \
            case GL_INVALID_OPERATION: \
                Donut_LogError("OpenGL Error: GL_INVALID_OPERATION"); \
                break; \
            case GL_INVALID_FRAMEBUFFER_OPERATION: \
                Donut_LogError("OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION"); \
                break; \
            case GL_OUT_OF_MEMORY: \
                Donut_LogError("OpenGL Error: GL_OUT_OF_MEMORY"); \
                break; \
            case GL_STACK_UNDERFLOW: \
                Donut_LogError("OpenGL Error: GL_STACK_UNDERFLOW"); \
                break; \
            case GL_STACK_OVERFLOW: \
                Donut_LogError("OpenGL Error: GL_STACK_OVERFLOW"); \
                break; \
            default: \
                Donut_LogError("OpenGL Error: Unknown error (%#x)", error); \
                break; \
        } \
    } \
}

#endif