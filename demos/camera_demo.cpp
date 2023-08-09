#include <iostream>
#include <memory>

#include "Donut/Donut.h"
#include "Donut/Donut_GL.h"
#include "Donut/Donut_GL_Texture.h"
#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Donut_GL_Utils.h"

float attributes[] = {
    // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
};

GLuint indices[] = 
{
    0, 1, 3,
    1, 2, 3
};

void renderLoop(float delta);
std::shared_ptr<Donut_GL_TextureVAO> VAO;
std::shared_ptr<Donut_GL_Texture> texture;
std::shared_ptr<Donut_GL_TextureProgram> program;

int main()
{
    Donut::init(500, 500, renderLoop);

    VAO = std::make_shared<Donut_GL_TextureVAO>(4, attributes);
    texture = std::shared_ptr<Donut_GL_Texture>(Donut_LoadTexture(Donut_GetAssetsPath("donut.png")));

    program = std::make_shared<Donut_GL_TextureProgram>();
    program->useProgram();
    program->setTextureUniform(texture.get());

    glBindVertexArray(VAO->getVAOid());

    while(Donut::updateRenderLoop());
}

void renderLoop(float delta)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(Donut::gWindow);

    Donut_glCheckErrorAll();
}