#ifndef Donut_GL_TextureVAO_h
#define Donut_GL_TextureVAO_h

#include "Donut/Donut_GL.h"

class Donut_GL_TextureVAO
{
public:
    Donut_GL_TextureVAO(int nAttribute, float * attributes);
    GLuint getVAOid();
    ~Donut_GL_TextureVAO();
private:
    GLuint mVAOid;
    GLuint mVBOid;
    GLuint mEBOid;
};
#endif