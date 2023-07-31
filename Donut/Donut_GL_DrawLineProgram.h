#ifndef DONUT_GL_DRAWLINEPROGRAM_H
#define DONUT_GL_DRAWLINEPROGRAM_H

#include "Donut_GL.h"
#include "Utils.h"
#include "Donut_ShadderSource.h"
#include "Donut.h"

class Donut_GL_DrawLineProgram
{
private:
    GLuint mProgramId;
public:
    Donut_GL_DrawLineProgram(/* args */);
	void useProgram();
    ~Donut_GL_DrawLineProgram();
};

void Donut_GL_DrawLineProgram::useProgram()
{
	glUseProgram(mProgramId);
}

Donut_GL_DrawLineProgram::Donut_GL_DrawLineProgram(/* args */)
{
    mProgramId = glCreateProgram();

    Donut_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);
	vertexShaderSource.compileShader(Donut_readfile(Donut_GetShadersPath("vertexShader.txt")).c_str());

	Donut_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	fragmentShaderSource.compileShader(Donut_readfile(Donut_GetShadersPath("fragmentShader.txt")).c_str());

    glAttachShader(mProgramId, fragmentShaderSource.getShader());
	glAttachShader(mProgramId, vertexShaderSource.getShader());
	glLinkProgram(mProgramId);

	GLint  success;
	char infoLog[512];
	glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);

	if(success != GL_TRUE) {
    	glGetProgramInfoLog(mProgramId, 512, NULL, infoLog);
		Donut_LogError("Shader program failed: %s", infoLog);

		Donut_Assert(false);
	}

    Donut_glCheckErrorAll();
}

Donut_GL_DrawLineProgram::~Donut_GL_DrawLineProgram()
{
	glDeleteProgram(mProgramId);
}

#endif

	// Donut_glCall(glGenVertexArrays(1, &VAO));

	// unsigned int VBO;
	// glGenBuffers(1, &VBO);

	// glBindVertexArray(VAO);

	// glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Donut_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);
	// vertexShaderSource.compileShader(Donut_readfile(Donut_GetShadersPath("vertexShader.txt")).c_str());

	// Donut_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	// fragmentShaderSource.compileShader(Donut_readfile(Donut_GetShadersPath("fragmentShader.txt")).c_str());

	// Donut_glCallAssign(shaderProgram, glCreateProgram());	

	// glAttachShader(shaderProgram, fragmentShaderSource.getShader());
	// glAttachShader(shaderProgram, vertexShaderSource.getShader());
	// glLinkProgram(shaderProgram);

	// GLint  success;
	// char infoLog[512];
	// glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	// if(success != GL_TRUE) {
    // 	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	// 	Donut_LogError("Shader program failed: %s", infoLog);
	// 	return false;
	// }

	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// glEnableVertexAttribArray(0);

	// Donut_glCheckErrorAll();
