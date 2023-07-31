#include <catch2/catch_test_macros.hpp>
#include "Donut/Donut.h"
#include "Donut/Utils.h"

TEST_CASE("Addition Test") {
    int result = 1 + 2;
    REQUIRE(result == 3);
}

TEST_CASE("Subtraction Test") {
    int result = 5 - 3;
    REQUIRE(result == 2);
}

TEST_CASE("DONUT LOG TEST") {
    DONUT_Log("hello world");
    DONUT_LogError("hwllodworld");
}

TEST_CASE("DONUT READ FILE")
{
    DONUT_Log(DONUT_readfile(DONUT_GetShadersPath("vertexShader.txt")).c_str());
}