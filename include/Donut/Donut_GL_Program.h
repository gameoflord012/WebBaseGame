#ifndef Donut_GL_Program_H
#define Donut_GL_Program_H

#include "Donut/Donut.h"
#include "Donut/Utils.h"
#include "Donut/Donut_ShadderSource.h"
#include "Donut/Donut.h"
#include "Donut/Donut_GL_Texture.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class Donut_GL_Program
{
public:
    Donut_GL_Program(const char * vertexShaderPath, const char * fragmentShaderPath);
	Donut_GL_Program(const Donut_ShaderSource & shaderSource, const Donut_ShaderSource & fragmentSource);
    ~Donut_GL_Program();
	
	void useProgram();
	GLuint getProgramId();

	void setTextureUniform(const Donut_GL_Texture & texture);
	void setMat4Uniform(const std::string& name, const glm::mat4& mat4);

	virtual void draw() {}
private:
    GLuint mProgramId;
};

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
