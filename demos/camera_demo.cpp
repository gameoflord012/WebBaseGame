#include <iostream>

#include <Donut/Donut.h>

void renderLoop(float delta);

int main()
{
    Donut::init(500, 500, renderLoop);

    while(Donut::updateRenderLoop());
}

void renderLoop(float delta)
{
    std::cout << delta << std::endl;
}