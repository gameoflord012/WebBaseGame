/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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


void initEntitites()
{
	donut = {Donut::loadTexture(DONUT_ASSETS_DIR(donut.png)), {0, 0, 700, 700}};

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
		SDL_Log( "Failed to initialize!\n" );
		return -1;
	}

	if(!MyOpenGL())
	{
		SDL_Log("OpenGL failed!");
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
	int  success;
	char infoLog[512];

	glGenVertexArrays(1, &VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	DONUT_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);

	vertexShaderSource.compileShader(R"(
		#version 330 core
		layout (location = 0) in vec3 aPos;
		void main()
		{
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
		};)");

	DONUT_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	fragmentShaderSource.compileShader(R"(
		#version 330 core
		out vec4 FragColor;
		void main()
		{
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
		};
	)");

	shaderProgram = glCreateProgram();	

	glAttachShader(shaderProgram, vertexShaderSource.getShader());
	glAttachShader(shaderProgram, fragmentShaderSource.getShader());
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if(!success) {
    	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		SDL_LogError(0, "Shader program failed: %s", infoLog);
		return false;
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	
	return true;
}

void MyOpenGLRender()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}