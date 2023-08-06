#include <catch2/catch_test_macros.hpp>
#include "Donut/Donut.h"
#include "Donut/Donut_GL_TextureProgram.h"
#include "Donut/Utils.h"
#include "Donut/Donut_GL_Utils.h"
#include <string>

TEST_CASE("Addition Test") {
    int result = 1 + 2;
    REQUIRE(result == 3);
}

TEST_CASE("Subtraction Test") {
    int result = 5 - 3;
    REQUIRE(result == 2);
}

TEST_CASE("Donut READ FILE")
{
    std::string file = Donut_readfile(Donut_GetShadersPath("vertexShader.txt"));
    REQUIRE(file.length() > 0);
}

TEST_CASE("Donut SHADER DRAWLINE PROGRAM")
{ 
    Donut::init(500, 500);

    Donut_GL_Texture * texture = Donut_LoadTexture(Donut_GetAssetsPath("donut.png"));

    Donut_GL_TextureVertexAttibute attributes[4] = {
        // positions            // colors          // texture coords
        {   0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f   },  // top right
        {   0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f   },  // bottom right
        { - 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,  },  // bottom left
        {   0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f   }   // top left 
    };

    Donut_GL_TextureVAO vao(3, attributes);
    Donut_GL_TextureProgram program;

    Donut_glCheckErrorAll();

    program.useProgram();

    Donut_glCheckErrorAll();

    program.setTextureUniform(texture);
    program.setVao(&vao);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}