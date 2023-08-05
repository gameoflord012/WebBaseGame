#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_Texture.h"

Donut_GL_TextureVAO::Donut_GL_TextureVAO(Donut_GL_TextureVertexAttibute attribute)
{
    glGenVertexArrays(1, &mId); 

    GLuint VBO;
    glGenBuffers(1, &VBO);

    glBindVertexArray(mId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(attribute.buffer), attribute.buffer, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
}

Donut_GL_TextureVAO::~Donut_GL_TextureVAO()
{
    glDeleteVertexArrays(1, &mId);
}
