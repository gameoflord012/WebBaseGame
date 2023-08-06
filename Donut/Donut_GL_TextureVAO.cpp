#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_Texture.h"

Donut_GL_TextureVAO::Donut_GL_TextureVAO(unsigned int size, Donut_GL_TextureVertexAttibute * attributes)
{
    glGenVertexArrays(1, &mId);

    GLuint VBO;
    glGenBuffers(1, &VBO);

    glBindVertexArray(mId);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Donut_GL_TextureVertexAttibute[0]) * size, attributes, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    Donut_glCheckErrorAll();
}

GLuint Donut_GL_TextureVAO::getId()
{
    return mId;
}
Donut_GL_TextureVAO::~Donut_GL_TextureVAO()
{
    glDeleteVertexArrays(1, &mId);
}
