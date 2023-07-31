// donut.h.in
#ifndef DONUT_H
#define DONUT_H

#include <SDL2/SDL.h>
#include <stdio.h>

#include "DONUT_GL.h"
#include "DONUT_Log.h"

#define DONUT_Assert(x) SDL_assert(x)

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
