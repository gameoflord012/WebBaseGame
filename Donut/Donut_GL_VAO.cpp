#include "Donut/Donut_GL_VAO.h"

Donut_GL_VAO::Donut_GL_VAO()
{
    glGenVertexArrays(1, &mVAOid);
    glGenBuffers(1, &mVBOid);
    glGenBuffers(1, &mEBOid);
    
    glBindVertexArray(mVAOid);
    glBindBuffer(GL_ARRAY_BUFFER, mVBOid);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBOid);

    glBindVertexArray(0);
    Donut_glCheckErrorAll();
}

GLuint Donut_GL_VAO::getVAOid()
{
    return mVAOid;
}

void Donut_GL_VAO::addAttributePointer(unsigned int nComponent, Donut_Type componentType, ptrdiff_t stride)
{

    glBindVertexArray(mVAOid);

    glVertexAttribPointer(nPointer, nComponent, CONVERT_GL_TYPE(componentType), GL_FALSE, stride, (void*)(pointerOffset));
    glEnableVertexAttribArray(nPointer);

    Donut_Log("%d %ld %d", nPointer, pointerOffset, CONVERT_GL_TYPE(componentType));

    nPointer++;
    pointerOffset += nComponent * SIZE_OF(componentType);

    glBindVertexArray(0);
    Donut_glCheckErrorAll();
}

void Donut_GL_VAO::setVBOdata(GLuint dataSize, void *data, GLuint flag)
{
    glBindVertexArray(mVAOid);

    glBindBuffer(GL_ARRAY_BUFFER, mVBOid);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, flag);

    glBindVertexArray(0);
    Donut_glCheckErrorAll();
}

void Donut_GL_VAO::setEBOdata(GLuint dataSize, void *data, GLuint flag)
{
    glBindVertexArray(mVAOid);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBOid);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, flag);

    glBindVertexArray(0);
    Donut_glCheckErrorAll();
}

Donut_GL_VAO::~Donut_GL_VAO()
{
    glDeleteVertexArrays(1, &mVAOid);
    glDeleteBuffers(1, &mVBOid);
    glDeleteBuffers(1, &mEBOid);
}