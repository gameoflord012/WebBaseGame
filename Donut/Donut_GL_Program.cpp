#include "Donut/Donut_GL_Program.h"

void Donut_GL_Program::useProgram()
{
	glUseProgram(mProgramId);
}

Donut_GL_Program::Donut_GL_Program(/* args */)
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

Donut_GL_Program::~Donut_GL_Program()
{
	glDeleteProgram(mProgramId);
}