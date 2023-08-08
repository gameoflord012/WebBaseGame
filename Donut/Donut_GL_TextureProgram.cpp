#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Utils.h"

Donut_GL_TextureProgram::Donut_GL_TextureProgram() : Donut_GL_Program(
    Donut_readfile(Donut_GetShadersPath("textureVertexShader.txt")).c_str(),
    Donut_readfile(Donut_GetShadersPath("textureFragmentShader.txt")).c_str())
{
}
void Donut_GL_TextureProgram::setTextureUniform(Donut_GL_Texture *texture)
{
    Donut_glCheckErrorAll();

    useProgram();

    glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
    glBindTexture(GL_TEXTURE_2D, texture->getId());

    Donut_glCheckErrorAll();

    glUniform1i(glGetUniformLocation(getProgramId(), "theTexture"), 0);

    Donut_glCheckErrorAll();
}