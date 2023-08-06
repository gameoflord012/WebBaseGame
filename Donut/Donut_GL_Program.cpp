#include "Donut/Donut_GL_Program.h"

void Donut_GL_Program::useProgram()
{
	glUseProgram(mProgramId);
}

GLuint Donut_GL_Program::getProgramId()
{
    return mProgramId;
}
Donut_GL_Program::Donut_GL_Program(const char *vertexShader, const char *fragmentShader)
{
    mProgramId = glCreateProgram();

    Donut_ShaderSource vertexShaderSource(GL_VERTEX_SHADER);
	vertexShaderSource.compileShader(vertexShader);

	Donut_ShaderSource fragmentShaderSource(GL_FRAGMENT_SHADER);
	fragmentShaderSource.compileShader(fragmentShader);

    glAttachShader(mProgramId, fragmentShaderSource.getShader());
	glAttachShader(mProgramId, vertexShaderSource.getShader());
	glLinkProgram(mProgramId);

	GLint  success;
	char infoLog[512];
	glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);

	Donut_assert(success == GL_TRUE, {
    	glGetProgramInfoLog(mProgramId, 512, NULL, infoLog);
		Donut_LogError("Shader program failed: %s", infoLog);
	});

    Donut_glCheckErrorAll();
}

Donut_GL_Program::~Donut_GL_Program()
{
	glDeleteProgram(mProgramId);
}