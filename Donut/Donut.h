// donut.h.in
#ifndef DONUT_H
#define DONUT_H

#include <GL/glew.h>
#include <SDL2/SDL.h>

#define DONUT_Log(...) SDL_Log(__VA_ARGS__)
#define DONUT_LogWarning(...) SDL_LogWarn( SDL_LOG_CATEGORY_CUSTOM, __VA_ARGS__)
#define DONUT_LogError(...) SDL_LogError(SDL_LOG_CATEGORY_CUSTOM, __VA_ARGS__)
#define DONUT_Critical(...) SDL_LogCritical(SDL_LOG_CATEGORY_CUSTOM, __VA_ARGS__)
#define DONUT_DebugLog(...) SDL_LogDebug(SDL_LOG_CATEGORY_CUSTOM, __VA_ARGS__)
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

#define DONUT_ASSETS_DIR(x) ("/home/swordmaster/Desktop/QtGame/assets/" #x)

#endif // DONUT_H