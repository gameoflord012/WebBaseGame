#ifndef Donut_GL_TextureProgram_H
#define Donut_GL_TextureProgram_H

#include <vector>
#include "Donut/Donut_GL_Program.h"
#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_Texture.h"
#include "Donut/Utils.h"

class Donut_GL_TextureProgram : public Donut_GL_Program
{
public:
    Donut_GL_TextureProgram();
    void setTextureUniform(Donut_GL_Texture * texture);
};
#endif