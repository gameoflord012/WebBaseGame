#ifndef Donut_GL_TextureVAO_h
#define Donut_GL_TextureVAO_h

#include "Donut/Donut_GL.h"
#include "Donut/Donut_GL_VAO.h"
#include "Donut/Donut_Rect.h"

#include <glm/glm.hpp>

class Donut_GL_TextureVAO : public Donut_GL_VAO
{
public:
    Donut_GL_TextureVAO(const Donut_Rect & rect);
};
#endif