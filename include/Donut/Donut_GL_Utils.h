#ifndef Donut_GL_Utils_h
#define Donut_GL_Utils_h

#include "Donut/Donut_GL_Texture.h"
#include <glm/glm.hpp>

Donut_GL_Texture * Donut_LoadTexture(const char *path);
float Donut_getAngle(glm::vec3 v1, glm::vec3 v2);

#endif