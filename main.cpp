/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "donut.h"
#include "utils.h"

void keyDown(int keycode);

bool quit = false;
Sprite donut;

void loop_handler(void*)
{
	//Event handler
	SDL_Event e;
	//Handle events on queue
	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			quit = true;
		}
		else if( e.type == SDL_KEYDOWN )
		{
			keyDown(e.key.keysym.sym);
		}
	}

	//Clear screen
	SDL_RenderClear( Donut::gRenderer );

	//Render texture to screen
	Donut::rendererCopySprite(donut);

	//Update screen
	SDL_RenderPresent( Donut::gRenderer );

}

void keyDown(int keycode)
{
	switch (keycode)
	{
	case SDLK_LEFT:
		donut.rect.x -= 5;
		break;
	case SDLK_RIGHT:
		donut.rect.x += 5;
		break;
	default:
		break;
	}
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !Donut::init(1000, 500) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//While application is running
		donut.rect.x = 0;
		donut.rect.y = 0;
		donut.rect.w = 100;
		donut.rect.h = 200;
		donut.texture = Donut::loadTexture(DONUT_ASSETS_DIR(donut.png));

		while( !quit )
		{
			loop_handler(NULL);	
		}
	}

	//Free resources and close SDL
	Donut::clean();

	return 0;
}