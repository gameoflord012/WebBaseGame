#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_Texture.h"

Donut_GL_TextureVAO::Donut_GL_TextureVAO(int nAttribute, float * attributes)
{
    glGenVertexArrays(1, &mVAOid);
    glBindVertexArray(mVAOid);

    glGenBuffers(1, &mVBOid);
    glBindBuffer(GL_ARRAY_BUFFER, mVBOid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8 * nAttribute, attributes, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    GLuint indices[] = { 0, 1, 3, 1, 2, 3 };
    glGenBuffers(1, &mEBOid);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBOid);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof indices, indices, GL_STATIC_DRAW);

    glBindVertexArray(0);

    Donut_glCheckErrorAll();
}

GLuint Donut_GL_TextureVAO::getId()
{
    return mVAOid;
}

Donut_GL_TextureVAO::~Donut_GL_TextureVAO()
{
    glDeleteVertexArrays(1, &mVAOid);
    glDeleteBuffers(1, &mVBOid);
    glDeleteBuffers(1, &mEBOid);
}
