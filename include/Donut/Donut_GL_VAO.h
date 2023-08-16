#ifndef Donut_GL_VAO_h
#define Donut_GL_VAO_h

#include "Donut/Donut_GL.h"

struct AttributePointer
{
    GLuint numComponents;
    GLuint type;
    GLuint offset;
};

#define CONVERT_GL_TYPE(x) (x & 0xFFFF)
#define SIZE_OF(x) (x >> 16)

enum Donut_Type
{
    DONUT_FLOAT = (GL_FLOAT | (4 << 16))
};

class Donut_GL_VAO
{
public:
    Donut_GL_VAO();
    GLuint getVAOid();
    void addAttributePointer(unsigned int nComponent, Donut_Type componentType, ptrdiff_t stride);
    void setVBOdata(GLuint dataSize, void * data, GLuint flag = GL_STATIC_DRAW);
    void setEBOdata(GLuint dataSize, void * data, GLuint flag = GL_STATIC_DRAW);
    ~Donut_GL_VAO();

private:
    GLuint mVAOid;
    GLuint mVBOid;
    GLuint mEBOid;
    unsigned int nPointer = 0;
    uintptr_t pointerOffset = 0;
};
#endif