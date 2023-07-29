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
