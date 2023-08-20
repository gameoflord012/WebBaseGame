#ifndef Donut_GridProgram_h
#define Donut_GridProgram_h

#include "Donut/Donut_GL_Program.h"
#include "Donut/Donut_Rect.h"

class Donut_GridProgram : public Donut_GL_Program
{
public:
    Donut_GridProgram();

private:
    Donut_Rect mRect;
    float division;
};

#endif