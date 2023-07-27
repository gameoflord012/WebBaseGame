// donut.h.in
#ifndef DONUT_H
#define DONUT_H

#include <SDL2/SDL.h>

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
};

#define DONUT_ASSETS_DIR(x) ("/home/swordmaster/Desktop/QtGame/assets/" #x)

#endif // DONUT_H
