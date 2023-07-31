/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <box2d/box2d.h>

#define DONUT_USE_GL
#define DONUT_DEBUG

#include "Donut/Donut.h"
#include "Donut/Utils.h"
#include "Donut/DONUT_ShadderSource.h"

b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);
Sprite donut;
b2Body * groundBody;

bool MyOpenGL();
void MyOpenGLRender();
void inputHandler(){}


void initEntitites()
{
	donut = {Donut::loadTexture(DONUT_GetAssetsPath("donut.png")), {0, 0, 700, 700}};

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
		DONUT_LogError( "Failed to initialize!\n" );
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

unsigned int shaderProgram;
GLuint VAO;

bool MyOpenGL()
{
	DONUT_glCall(glGenVertexArrays(1, &VAO));

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	DONUT_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);
	vertexShaderSource.compileShader(DONUT_readfile(DONUT_GetShadersPath("vertexShader.txt")).c_str());

	DONUT_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	fragmentShaderSource.compileShader(DONUT_readfile(DONUT_GetShadersPath("fragmentShader.txt")).c_str());

	DONUT_glCallAssign(shaderProgram, glCreateProgram());	

	glAttachShader(shaderProgram, vertexShaderSource.getShader());
	glAttachShader(shaderProgram, fragmentShaderSource.getShader());
	glLinkProgram(shaderProgram);

	GLint  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if(success != GL_TRUE) {
    	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		DONUT_LogError("Shader program failed: %s", infoLog);
		return false;
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	DONUT_glCheckErrorAll();

	return true;
}

void MyOpenGLRender()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	glPointSize(10.0);
	glDrawArrays(GL_POINTS, 0, 3);
}