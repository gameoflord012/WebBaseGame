// donut.h.in
#ifndef DONUT_H
#define DONUT_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <map>

#include "Donut/Donut_GL.h"
#include "Donut/Donut_Log.h"

#define DONUT_ASSETS_DIR "/home/swordmaster/Desktop/WebBaseGame/assets/"
#define DONUT_SHADERS_DIR "/home/swordmaster/Desktop/WebBaseGame/shaders/"

#define Donut_GetAssetsPath(path) DONUT_ASSETS_DIR path
#define Donut_GetShadersPath(path) DONUT_SHADERS_DIR path

struct Sprite
{
    SDL_Texture * texture;
    SDL_Rect rect;
};

struct MouseData
{
    int offsetX, offsetY;
    int previousX, previousY, mouseX, mouseY;

    bool isLeftMouseDown = false;
    bool isRightMouseDown = false;

    int mouseScrollOffset = 0;
};

typedef void (*RenderLoopFunc)(float delta);
typedef void (*EventLoopHandlerFunc)(const SDL_Event &e);

class Donut
{
public:
    static SDL_Window* gWindow;
    static SDL_Renderer* gRenderer;

    static bool init(int screenWidth, int screenHeight,  RenderLoopFunc renderloop = NULL);
    static void setEventLoopHandler(EventLoopHandlerFunc eventLoopHandler);
    static void rendererCopySprite( Sprite sprite );
    static void clean();
    static bool isKeyPressed(SDL_KeyCode keyCode);
    static SDL_Texture* loadTexture( const char * path );
    static bool updateLoops();
    static MouseData getMouseData();

private:
    static RenderLoopFunc gRenderLoop;
    static EventLoopHandlerFunc gEventLoopHandler;
    static int gScreenWidth;
    static int gScreenHeight;
    static SDL_GLContext gContext;
    static Uint32 gRenderLoopTimer;
    static MouseData gMouseData;
    static std::map<uint32_t, bool> gIsKeyPressed;
};

#endif // DONUT_H
