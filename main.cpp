/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>
#include <iostream>

#include "SDL2/SDL.h"

#define DONUT_USE_GL
#define DONUT_DEBUG

#include "Donut/Donut.h"
#include "Donut/Utils.h"
#include "Donut/Donut_ShadderSource.h"
#include "Donut/Donut_GL_Program.h"
#include "Donut/Donut_GL.h"

Sprite donut;

bool MyOpenGL();
void MyOpenGLRender();
void inputHandler(){}


void initEntitites()
{
	donut = {Donut::loadTexture(Donut_GetAssetsPath("donut.png")), {0, 0, 700, 700}};
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !Donut::init(1000, 500) )
	{
		Donut_LogError( "Failed to initialize!\n" );
		return -1;
	}

	if(!MyOpenGL())
	{
		SDL_Log("MyOpenGL failed!");
		return -1;
	}

	bool quit = false;
	Uint32 startTime = SDL_GetTicks();
	float deltaTimeInSeconds;

	while(!quit)
	{
		deltaTimeInSeconds = (float)(SDL_GetTicks() - startTime) / 1000.;
		startTime = SDL_GetTicks();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		MyOpenGLRender();

		SDL_Event e;
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quitit ad
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN )
			{
				inputHandler();
			}
		}

		SDL_GL_SwapWindow(Donut::gWindow);
	}

	//Free resources and close SDL
	Donut::clean();

	return 0;
}

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  

std::shared_ptr<Donut_GL_Program> shaderProgram;
GLuint VAO;

bool MyOpenGL()
{
	glGenVertexArrays(1, &VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	shaderProgram = std::make_shared<Donut_GL_Program>(
		Donut_readfile(Donut_GetShadersPath("vertexShader.txt")).c_str(),
		Donut_readfile(Donut_GetShadersPath("fragmentShader.txt")).c_str());

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	Donut_glCheckErrorAll();

	return true;
}

void MyOpenGLRender()
{
	glBindVertexArray(VAO);
	shaderProgram->useProgram();

	glPointSize(10.0);
	glDrawArrays(GL_POINTS, 0, 3);
}