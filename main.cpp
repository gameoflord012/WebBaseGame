/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Donut/donut.h"
#include "Donut/utils.h"

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !Donut::init(1000, 500) )
	{
		printf( "Failed to initialize!\n" );
		return -1;
	}

	Sprite donut;

	donut.rect.x = 0;
	donut.rect.y = 0;
	donut.rect.w = 100;
	donut.rect.h = 200;
	donut.texture = Donut::loadTexture(DONUT_ASSETS_DIR(donut.png));

	SDL_Event e;
	bool quit = false;

	Uint32 startTime = SDL_GetTicks();
	float deltaTimeInSeconds;

	while(!quit)
	{
		deltaTimeInSeconds = (float)(SDL_GetTicks() - startTime) / 1000.;
		startTime = SDL_GetTicks();

		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN )
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					donut.rect.x -= 100 * deltaTimeInSeconds;
					break;
				case SDLK_RIGHT:
					donut.rect.x += 100 * deltaTimeInSeconds;
					break;
				default:
					break;
				}
			}
		}
		
		//Clear screen
		SDL_RenderClear( Donut::gRenderer );

		//Render texture to screen
		Donut::rendererCopySprite(donut);

		//Update screen
		SDL_RenderPresent( Donut::gRenderer );
	}

	//Free resources and close SDL
	Donut::clean();

	return 0;
}