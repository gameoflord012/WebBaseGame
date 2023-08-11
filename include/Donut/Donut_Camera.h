#ifndef Donut_Camera_h
#define Donut_Camera_h

#include "Donut/Donut_GL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Donut_Camera
{
    public:
        Donut_Camera();
        glm::mat4 getViewMat() const;
        glm::mat4 getProjectionMat() const;
    private:
        glm::mat4 mView;
        glm::mat4 mProjection;
};
#endif