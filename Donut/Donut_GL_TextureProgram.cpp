#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Utils.h"

Donut_GL_TextureProgram::Donut_GL_TextureProgram() : Donut_GL_Program(
    Donut_readfile(Donut_GetShadersPath("vertexShader.txt")).c_str(),
    Donut_readfile(Donut_GetShadersPath("fragmentShader.txt")).c_str())
{
}