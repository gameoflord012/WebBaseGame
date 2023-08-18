#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Utils.h"

Donut_GL_TextureProgram::Donut_GL_TextureProgram() : Donut_GL_Program("camera.vs", "textureFragmentShader.txt")
{
    mProgramVAO.addAttributePointer(3, DONUT_FLOAT, 8 * sizeof(float));
    mProgramVAO.addAttributePointer(3, DONUT_FLOAT, 8 * sizeof(float));
    mProgramVAO.addAttributePointer(2, DONUT_FLOAT, 8 * sizeof(float));

    mProgramVAO.createVBOdata(sizeof(float) * 32, nullptr, GL_STREAM_DRAW);

    uint32_t indices[] = {
        2, 0, 3,
        2, 1, 0
    };
    
    mProgramVAO.setEBOdata(sizeof indices, indices);
}

void Donut_GL_TextureProgram::setRect(const Donut_Rect & rect)
{
    mRect = rect;
}

void Donut_GL_TextureProgram::draw()
{
    float * vertexData = getTextureVertexData();
    mProgramVAO.changeVBOdata(sizeof(float) * 32, vertexData);
    delete[] vertexData;

    glBindVertexArray(mProgramVAO.getVAOid());
    useProgram();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
float *Donut_GL_TextureProgram::getTextureVertexData()
{
    float * arr = new float[32] {
    // positions          // colors           // texture coords
        mRect.px + mRect.width / 2.f, mRect.py + mRect.height / 2.f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
        mRect.px + mRect.width / 2.f, mRect.py - mRect.height / 2.f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        mRect.px - mRect.width / 2.f, mRect.py - mRect.height / 2.f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        mRect.px - mRect.width / 2.f, mRect.py + mRect.height / 2.f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    return arr;
}