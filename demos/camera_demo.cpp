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

Donut_Camera camera;

int main()
{
    Donut::init(500, 500, renderLoop);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    VAO = std::make_shared<Donut_GL_TextureVAO>(4, attributes);
    texture = std::shared_ptr<Donut_GL_Texture>(Donut_LoadTexture(Donut_GetAssetsPath("donut1.png")));

    program = std::make_shared<Donut_GL_Program>(
        Donut_ShaderSource(DONUT_VERTEX_SHADER, "camera.vs"),
        Donut_ShaderSource(DONUT_FRAGMENT_SHADER, "textureFragmentShader.txt"));
        
    program->setTextureUniform(texture.get());
    program->setMat4Uniform("model", model);

    program->useProgram();
    glBindVertexArray(VAO->getVAOid());

    while(Donut::updateRenderLoop());
}

float camX, camZ;

void renderLoop(float delta)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // const float radius = 3.0f;
    // camX = sin((float)SDL_GetTicks() / 100) * radius;
    // camZ = cos((float)SDL_GetTicks() / 100) * radius;
    // glm::mat4 view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0)); 

    program->setMat4Uniform("view", camera.getViewMat());
    program->setMat4Uniform("projection", camera.getProjectionMat());

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(Donut::gWindow);

    Donut_glCheckErrorAll();
}