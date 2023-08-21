#include "Donut/Donut.h"

void renderLoop(float delta);

void new_frame_event()
{
    Donut_Log("New frame!");
}

int main()
{
    Donut::init(800, 800, renderLoop);
    Donut::get_NewFrameEventListeners().insert(new_frame_event);

    while(Donut::updateLoops());
}

void renderLoop(float delta)
{
}