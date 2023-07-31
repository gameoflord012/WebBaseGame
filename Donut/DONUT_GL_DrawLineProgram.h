#ifndef DONUT_GL_DRAWLINEPROGRAM_H
#define DONUT_GL_DRAWLINEPROGRAM_H

#include "DONUT_GL.h"
#include "Utils.h"
#include "DONUT_ShadderSource.h"
#include "Donut.h"

class DONUT_GL_DrawLineProgram
{
private:
    GLuint mProgramId;
public:
    DONUT_GL_DrawLineProgram(/* args */);
    ~DONUT_GL_DrawLineProgram();
};

DONUT_GL_DrawLineProgram::DONUT_GL_DrawLineProgram(/* args */)
{
    mProgramId = glCreateProgram();

    DONUT_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);
	vertexShaderSource.compileShader(DONUT_readfile(DONUT_GetShadersPath("vertexShader.txt")).c_str());

	DONUT_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	fragmentShaderSource.compileShader(DONUT_readfile(DONUT_GetShadersPath("fragmentShader.txt")).c_str());

    glAttachShader(mProgramId, fragmentShaderSource.getShader());
	glAttachShader(mProgramId, vertexShaderSource.getShader());
	glLinkProgram(mProgramId);

	GLint  success;
	char infoLog[512];
	glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);

	if(success != GL_TRUE) {
    	glGetProgramInfoLog(mProgramId, 512, NULL, infoLog);
		DONUT_LogError("Shader program failed: %s", infoLog);

		DONUT_Assert(false);
	}

    DONUT_glCheckErrorAll();
}

DONUT_GL_DrawLineProgram::~DONUT_GL_DrawLineProgram()
{
	glDeleteProgram(mProgramId);
}

#endif

	// DONUT_glCall(glGenVertexArrays(1, &VAO));

	// unsigned int VBO;
	// glGenBuffers(1, &VBO);

	// glBindVertexArray(VAO);

	// glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// DONUT_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);
	// vertexShaderSource.compileShader(DONUT_readfile(DONUT_GetShadersPath("vertexShader.txt")).c_str());

	// DONUT_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	// fragmentShaderSource.compileShader(DONUT_readfile(DONUT_GetShadersPath("fragmentShader.txt")).c_str());

	// DONUT_glCallAssign(shaderProgram, glCreateProgram());	

	// glAttachShader(shaderProgram, fragmentShaderSource.getShader());
	// glAttachShader(shaderProgram, vertexShaderSource.getShader());
	// glLinkProgram(shaderProgram);

	// GLint  success;
	// char infoLog[512];
	// glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	// if(success != GL_TRUE) {
    // 	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	// 	DONUT_LogError("Shader program failed: %s", infoLog);
	// 	return false;
	// }

	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// glEnableVertexAttribArray(0);

	// DONUT_glCheckErrorAll();
