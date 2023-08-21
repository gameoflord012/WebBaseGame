#include "Donut/Donut.h"

void renderLoop(float delta);

int main()
{
    Donut::init(800, 800, renderLoop);

    while(Donut::updateLoops());
}

void renderLoop(float delta)
{
}