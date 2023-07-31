// donut.h.in
#ifndef DONUT_H
#define DONUT_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <stdio.h>

#define DONUT_ANSI_COLOR_RED     "\x1b[31m"
#define DONUT_ANSI_COLOR_GREEN   "\x1b[32m"
#define DONUT_ANSI_COLOR_YELLOW  "\x1b[33m"
#define DONUT_ANSI_COLOR_BLUE    "\x1b[34m"
#define DONUT_ANSI_COLOR_RESET   "\x1b[0m"


#define DONUT_Log(...)          { printf(DONUT_ANSI_COLOR_BLUE "[INFO]    " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogWarning(...)   { printf(DONUT_ANSI_COLOR_YELLOW "[WARNING] " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogError(...)     { printf(DONUT_ANSI_COLOR_RED "[ERROR]   " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogCritical(...)  { printf(DONUT_ANSI_COLOR_RED "[CRITICAL]" DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
#define DONUT_LogDebug(...)     { printf(DONUT_ANSI_COLOR_YELLOW "[DEBUG]   " DONUT_ANSI_COLOR_RESET);  printf(__VA_ARGS__,"\n"); }
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

struct Sprite
{
    SDL_Texture * texture;
    SDL_Rect rect;
};

class Donut
{
public:
    static SDL_Window* gWindow;
    static SDL_Renderer* gRenderer;

    static bool init(int screenWidth, int screenHeight);
    static void rendererCopySprite( Sprite sprite );
    static void clean();
    static SDL_Texture* loadTexture( const char * path );

private:
    static int gScreenWidth;
    static int gScreenHeight;
    static SDL_GLContext gContext;
};

#define DONUT_ASSETS_DIR "/home/swordmaster/Desktop/QtGame/assets/"
#define DONUT_SHADERS_DIR "/home/swordmaster/Desktop/QtGame/shaders/"
#define DONUT_GetAssetsPath(path) DONUT_ASSETS_DIR path
#define DONUT_GetShadersPath(path) DONUT_SHADERS_DIR path

#endif // DONUT_H
