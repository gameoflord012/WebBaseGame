#ifndef Donut_GL_TextureProgram_H
#define Donut_GL_TextureProgram_H

#include <vector>
#include <memory>

#include "Donut/Donut_GL_Program.h"
#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_Texture.h"
#include "Donut/Utils.h"
#include "Donut/Donut_Camera.h"

class Donut_GL_TextureProgram : public Donut_GL_Program
{
public:
    Donut_GL_TextureProgram();
    void setRect(const Donut_Rect & rect);
    void draw() override;

private:
    float * getTextureVertexData();

    Donut_GL_VAO mProgramVAO;
    Donut_Rect mRect = {0, 0, 1, 1};
};
#endif