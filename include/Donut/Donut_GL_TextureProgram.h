#ifndef Donut_GL_TextureProgram_H
#define Donut_GL_TextureProgram_H

#include <vector>
#include "Donut/Donut_GL_Program.h"
#include "Donut/Utils.h"

class Donut_GL_TextureProgram : private Donut_GL_Program
{
public:
    Donut_GL_TextureProgram();
    void addAttribute(Donut_GL_TextureVertexAttibute attribute);
};
#endif