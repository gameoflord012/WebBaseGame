#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Utils.h"

Donut_GL_TextureProgram::Donut_GL_TextureProgram() : Donut_GL_Program(
    Donut_readfile(Donut_GetShadersPath("textureVertexShader.txt")).c_str(),
    Donut_readfile(Donut_GetShadersPath("textureFragmentShader.txt")).c_str())
{
}