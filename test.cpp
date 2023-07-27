#include <catch2/catch_test_macros.hpp>

TEST_CASE("Addition Test") {
    int result = 1 + 2;
    REQUIRE(result == 3);
}

TEST_CASE("Subtraction Test") {
    int result = 5 - 3;
    REQUIRE(result == 2);
}