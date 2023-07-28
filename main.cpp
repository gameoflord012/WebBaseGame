/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <box2d/box2d.h>
#include "Donut/donut.h"
#include "Donut/utils.h"

b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);
Sprite donut;
b2Body * groundBody;

void initEntitites()
{
	donut = {{Donut::loadTexture(DONUT_ASSETS_DIR(donut.png))}, {0, 0, 700, 700}};

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	
	groundBody->CreateFixture(&groundBox, 0.0f);
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !Donut::init(1000, 500) )
	{
		printf( "Failed to initialize!\n" );
		return -1;
	}

	initEntitites();

	bool quit = false;
	Uint32 startTime = SDL_GetTicks();
	float deltaTimeInSeconds;

	while(!quit)
	{
		deltaTimeInSeconds = (float)(SDL_GetTicks() - startTime) / 1000.;
		startTime = SDL_GetTicks();

		SDL_Event e;
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