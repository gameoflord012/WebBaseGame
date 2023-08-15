#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Donut/Donut.h"
#include "Donut/Donut_GL.h"
#include "Donut/Donut_GL_Texture.h"
#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Donut_GL_Utils.h"
#include "Donut/Donut_Camera.h"

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
std::shared_ptr<Donut_GL_Program> program;

Donut_Camera camera(glm::vec3(0, 0.1, -3), glm::vec3(0, 0, 0));

int main()
{
    Donut::init(800, 800, renderLoop);

    VAO = std::make_shared<Donut_GL_TextureVAO>(4, attributes);
    texture = std::shared_ptr<Donut_GL_Texture>(Donut_LoadTexture(Donut_GetAssetsPath("donut.png")));

    program = std::make_shared<Donut_GL_Program>(
        Donut_ShaderSource(DONUT_VERTEX_SHADER, "camera.vs"),
        Donut_ShaderSource(DONUT_FRAGMENT_SHADER, "textureFragmentShader.txt"));
        
    program->setTextureUniform(texture.get());
    program->setMat4Uniform("model", glm::mat4(1.0f));

    program->useProgram();
    glBindVertexArray(VAO->getVAOid());

    while(Donut::updateLoops());
}

float mouseSens = 10;

void renderLoop(float delta)
{
    MouseData mouseData = Donut::getMouseData();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if(Donut::getMouseData().isMouseDown)
    {
        camera.rotate(
            glm::radians((float)mouseData.offsetX * 10) * delta, 
            glm::radians((float)mouseData.offsetY * 10) * delta);
    }

    program->setMat4Uniform("view", camera.caculateViewMat());
    program->setMat4Uniform("projection", camera.getProjectionMat());
 
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(Donut::gWindow);

    Donut_glCheckErrorAll();
}