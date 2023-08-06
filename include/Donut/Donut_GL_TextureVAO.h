#ifndef Donut_GL_TextureVAO_h
#define Donut_GL_TextureVAO_h

#include "Donut/Donut_GL.h"

struct Donut_GL_TextureVertexAttibute
{
    float buffer[8];

    void setPosition(float px, float py, float pz)
    {
        buffer[0] = px;
        buffer[1] = py;
        buffer[2] = pz;
    };

    void setColor(float r, float g, float b)
    {
        buffer[3] = r;
        buffer[4] = g;
        buffer[5] = b;
    }

    void setTextureCoords(float x, float y)
    {
        buffer[6] = x;
        buffer[7] = y;
    }
};

class Donut_GL_TextureVAO
{
public:
    Donut_GL_TextureVAO(unsigned int size, Donut_GL_TextureVertexAttibute * attributes);
    ~Donut_GL_TextureVAO();
private:
    GLuint mId;
};
#endif