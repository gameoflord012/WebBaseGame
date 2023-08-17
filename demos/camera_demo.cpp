#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>

#include "Donut/Donut.h"
#include "Donut/Donut_GL.h"
#include "Donut/Donut_GL_Texture.h"
#include "Donut/Donut_GL_TextureVAO.h"
#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Donut_GL_Utils.h"
#include "Donut/Donut_Camera.h"
#include "Donut/Donut_GL_VAO.h"

float attributes[] = {
    // positions          // colors           // texture coords
         2.f,  2.f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         2.f, -2.f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -2.f, -2.f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -2.f,  2.f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
};

GLuint indices[] = 
{
    2, 0, 3,
    2, 1, 0
};

void renderLoop(float delta);
void eventLoop(const SDL_Event &e);

std::shared_ptr<Donut_GL_TextureVAO> VAO;
std::shared_ptr<Donut_GL_Texture> texture;
std::shared_ptr<Donut_GL_Program> program;

Donut_Camera camera(glm::vec3(0, 0.1, 3), glm::vec3(0, 0, 0));

int main()
{
    Donut::init(800, 800, renderLoop);
    Donut::setEventLoopHandler(eventLoop);

    VAO = std::make_shared<Donut_GL_TextureVAO>(Donut_Rect {0, 0, 2, 2});

    texture = std::shared_ptr<Donut_GL_Texture>(Donut_LoadTexture(Donut_GetAssetsPath("hello_world.bmp")));

    program = std::make_shared<Donut_GL_Program>(
        Donut_ShaderSource(DONUT_VERTEX_SHADER, "camera.vs"),
        Donut_ShaderSource(DONUT_FRAGMENT_SHADER, "textureFragmentShader.txt"));
        
    program->setTextureUniform(texture.get());

    program->useProgram();

    while(Donut::updateLoops());
}

float mouseSens = 10;
glm::vec<3, int> moveDirection;

void cameraInputHandler(float delta)
{
    MouseData mouseData = Donut::getMouseData();

    if(Donut::getMouseData().isMouseDown)
    {
        camera.rotate(
            glm::radians((float)mouseData.offsetX * 10) * delta, 
            glm::radians((float)mouseData.offsetY * 10) * delta);
    }

    camera.move(moveDirection.x * delta, moveDirection.y * delta, moveDirection.z * delta);
}

void renderLoop(float delta)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    cameraInputHandler(delta);
    
    glBindVertexArray(VAO->getVAOid());
    Donut_glCheckErrorAll();

    program->setMat4Uniform("model", glm::mat4(1.0f));
    program->setMat4Uniform("view", camera.caculateViewMat());
    program->setMat4Uniform("projection", camera.getProjectionMat());
 
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(Donut::gWindow);

    Donut_glCheckErrorAll();
}


void eventLoop(const SDL_Event &event)
{
    moveDirection.x = Donut::isKeyPressed(SDLK_a) * -1 + Donut::isKeyPressed(SDLK_d);
    moveDirection.y = Donut::isKeyPressed(SDLK_LSHIFT) * -1 + Donut::isKeyPressed(SDLK_SPACE);
    moveDirection.z = Donut::isKeyPressed(SDLK_s) * -1 + Donut::isKeyPressed(SDLK_w);

    //Donut_Log("%d %d %d", moveDirection.x, moveDirection.y, moveDirection.z);
}
