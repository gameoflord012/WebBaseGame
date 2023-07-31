#ifndef DONUT_GL
#define DONUT_GL
#include <GL/glew.h>

#define DONUT_glCheckError(errorEnum) {\
    GLenum error;\
    while((error = glGetError()) != GL_NO_ERROR)\
    {\
        if(error == errorEnum) DONUT_LogError("Donut check gl Error failed: %s", #errorEnum);\
    }\
}
#define DONUT_glCheckErrorAll() {\
    GLenum error;\
    while ((error = glGetError()) != GL_NO_ERROR) {\
        switch (error) {\
            case GL_INVALID_ENUM:\
                DONUT_LogError("OpenGL Error: GL_INVALID_ENUM");\
                break;\
            case GL_INVALID_VALUE:\
                DONUT_LogError("OpenGL Error: GL_INVALID_VALUE");\
                break;\
            case GL_INVALID_OPERATION:\
                DONUT_LogError("OpenGL Error: GL_INVALID_OPERATION");\
                break;\
            case GL_INVALID_FRAMEBUFFER_OPERATION:\
                DONUT_LogError("OpenGL Error: GL_INVALID_FRAMEBUFFER_OPERATION");\
                break;\
            case GL_OUT_OF_MEMORY:\
                DONUT_LogError("OpenGL Error: GL_OUT_OF_MEMORY");\
                break;\
            case GL_STACK_UNDERFLOW:\
                DONUT_LogError("OpenGL Error: GL_STACK_UNDERFLOW");\
                break;\
            case GL_STACK_OVERFLOW:\
                DONUT_LogError("OpenGL Error: GL_STACK_OVERFLOW");\
                break;\
            default:\
                DONUT_LogError("OpenGL Error: Unknown error (%#x)", error);\
                break;\
        }\
    }\
}
#define DONUT_glCallAssign(assign, glcall) { assign=glcall; DONUT_glCheckErrorAll(); }
#define DONUT_glCall(glcall) { glcall; DONUT_glCheckErrorAll(); }
#endif