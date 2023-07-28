#include "donut.h"
#include <SDL2/SDL_image.h>

SDL_Window* Donut::gWindow = NULL;
SDL_Renderer* Donut::gRenderer = NULL;
SDL_GLContext Donut::gContext = NULL;


bool Donut::init(int screenWidth, int screenHeight)
{
    //Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

		//Create window
		Donut::gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
		if( Donut::gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gContext = SDL_GL_CreateContext( gWindow );

			if(gContext == NULL)
			{
				SDL_LogError( 0, "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
			}

			GLenum err = glewInit();
			if (GLEW_OK != err)
			{
				/* Problem: glewInit failed, something is seriously wrong. */
				SDL_LogError(0, "Error: %s\n", glewGetErrorString(err));
			}

			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

			//try software render if hardware fails
			if( gRenderer == NULL )
			{
				SDL_Log( "Accelerated renderer could not be created! SDL Error: %s\nSwitching to software renderer", SDL_GetError() );
				gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_SOFTWARE);
			}

			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void Donut::rendererCopySprite( Sprite sprite )
{
	SDL_RenderCopy( Donut::gRenderer, sprite.texture, NULL, &sprite.rect );
}

SDL_Texture* Donut::loadTexture( const char * path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Donut::clean()
{
    //Destroy window	
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
