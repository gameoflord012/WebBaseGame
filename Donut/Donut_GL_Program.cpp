#include "Donut/Donut_GL_Program.h"
#include "Donut/Donut_GL.h"

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
    Donut_ShaderSource vertexShaderSource(DONUT_VERTEX_SHADER);
	vertexShaderSource.compileShader(vertexShader);

	Donut_ShaderSource fragmentShaderSource(DONUT_FRAGMENT_SHADER);
	fragmentShaderSource.compileShader(fragmentShader);

    Donut_GL_Program(vertexShaderSource, fragmentShaderSource);
}

Donut_GL_Program::Donut_GL_Program(const Donut_ShaderSource & vertexShaderSource, const Donut_ShaderSource & fragmentShaderSource)
{
	mProgramId = glCreateProgram();

	glAttachShader(mProgramId, vertexShaderSource.getShader());
	glAttachShader(mProgramId, fragmentShaderSource.getShader());
	glLinkProgram(mProgramId);

	GLint  success;
	glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);

	Donut_assert(success == GL_TRUE, {

		GLint logLength;
		glGetProgramiv(mProgramId, GL_INFO_LOG_LENGTH, &logLength);

		if (logLength > 0) {
			GLchar* infoLog = new GLchar[logLength + 1]; // +1 for null-terminator
			glGetProgramInfoLog(mProgramId, logLength, &logLength, infoLog);

			// Print the log content
			Donut_LogError("Shader program failed: %s", infoLog);
			delete[] infoLog; // Clean up the dynamically allocated memory
		}
	});

    Donut_glCheckErrorAll();
}

void Donut_GL_Program::setTextureUniform(const Donut_GL_Texture *texture)
{
    useProgram();

    glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
    glBindTexture(GL_TEXTURE_2D, texture->getId());

    glUniform1i(glGetUniformLocation(getProgramId(), "theTexture"), 0);

    Donut_glCheckErrorAll();
}

void Donut_GL_Program::setMat4Uniform(const std::string& name, const glm::mat4& mat4)
{
	useProgram();
	glUniformMatrix4fv(glGetUniformLocation(getProgramId(), name.c_str()), 1, GL_FALSE, glm::value_ptr(mat4));
    Donut_glCheckErrorAll();
}

Donut_GL_Program::~Donut_GL_Program()
{
	glDeleteProgram(mProgramId);
}