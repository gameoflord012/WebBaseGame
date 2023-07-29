#ifndef DONUT_SHADERSOURCE_H
#define DONUT_SHADERSOURCE_H

#include "Donut.h"

class DONUT_ShaderSource
{
public:
    DONUT_ShaderSource(GLuint shaderType);
    bool compileShader(const char * shaderSource);

private:
    GLuint vertexShader;
    char * mShaderSourcestring;
};

// unsigned int vertexShader;
// 	vertexShader = glCreateShader(GL_VERTEX_SHADER);
// 	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
// 	glCompileShader(vertexShader);

// 	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

// 	if(!success)
// 	{
// 		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
// 		SDL_LogError(0, "%s", infoLog);
// 		return false;
// 	}

#endif