#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_Texture.h"

#include <glm/glm.hpp>

Donut_GL_TextureVAO::Donut_GL_TextureVAO(const Donut_Rect & rect) : Donut_GL_VAO()
{
    addAttributePointer(3, DONUT_FLOAT, 8 * sizeof(float));
    addAttributePointer(3, DONUT_FLOAT, 8 * sizeof(float));
    addAttributePointer(2, DONUT_FLOAT, 8 * sizeof(float));

    float attributes[] = {
    // positions          // colors           // texture coords
        rect.px + rect.width / 2.f, rect.py + rect.height / 2.f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
        rect.px + rect.width / 2.f, rect.py - rect.height / 2.f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        rect.px - rect.width / 2.f, rect.py - rect.height / 2.f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        rect.px - rect.width / 2.f, rect.py + rect.height / 2.f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    uint32_t indices[] = 
    {
        2, 0, 3,
        2, 1, 0
    };

    createVBOdata(sizeof attributes, attributes);
    setEBOdata(sizeof indices, indices);

    Donut_glCheckErrorAll();

    // glGenVertexArrays(1, &mVAOid);
    // glBindVertexArray(mVAOid);

    // glGenBuffers(1, &mVBOid);
    // glBindBuffer(GL_ARRAY_BUFFER, mVBOid);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8 * nAttribute, attributes, GL_STATIC_DRAW);

    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 0);
    // glEnableVertexAttribArray(0);

    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);

    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    // glEnableVertexAttribArray(2);


    // GLuint indices[] = { 0, 1, 3, 1, 2, 3 };
    // glGenBuffers(1, &mEBOid);
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBOid);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof indices, indices, GL_STATIC_DRAW);

    // glBindVertexArray(0);

    // Donut_glCheckErrorAll();
}
