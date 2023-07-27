/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#ifdef _JS
#include <emscripten.h>
#endif

#include "donut.h"
#include "utils.h"

void keyDown(SDL_Keycode keycode) {}
//The window we'll be rendering to

//Main loop flag
bool quit = false;

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

	Sprite donut;
	donut.rect.x = 0;
	donut.rect.y = 0;
	donut.rect.w = 100;
	donut.rect.h = 200;
	donut.texture = Donut::loadTexture(DONUT_ASSETS_DIR(donut.png));

	//Render texture to screen
	Donut::rendererCopySprite(donut);

	//Update screen
	SDL_RenderPresent( Donut::gRenderer );

}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !Donut::init(500, 250) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
#ifdef _JS

		emscripten_set_main_loop_arg(loop_handler, NULL, -1, 1); 
#else
		//While application is running
		while( !quit )
		{
			loop_handler(NULL);	
		}
#endif
	}

	//Free resources and close SDL
	Donut::clean();

	return 0;
}