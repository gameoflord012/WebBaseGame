#include <catch2/catch_test_macros.hpp>
#include "Donut/Donut.h"
#include "Donut/Donut_GL_DrawLineProgram.h"
#include "Donut/Utils.h"
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
    Donut::init(5, 5);
    Donut_GL_DrawLineProgram program;
    Donut::clean();
}