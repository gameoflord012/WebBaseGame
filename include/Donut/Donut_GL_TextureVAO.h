#ifndef Donut_GL_TextureVAO_h
#define Donut_GL_TextureVAO_h

#include "Donut/Donut_GL.h"
#include "Donut/Donut_GL_VAO.h"

#include <glm/glm.hpp>

struct Donut_Rect
{
    float px, py;
    float width, height;
};

class Donut_GL_TextureVAO : public Donut_GL_VAO
{
public:
    Donut_GL_TextureVAO(const Donut_Rect & rect);
};
#endif