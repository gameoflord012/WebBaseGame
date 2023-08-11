#include "Donut/Donut_Camera.h"

Donut_Camera::Donut_Camera()
{
    mView = glm::mat4(1.0f);
    mView = glm::translate(mView, glm::vec3(0.0f, 0.0f, -2.0f)); 
    mProjection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

glm::mat4 Donut_Camera::getViewMat() const
{
    return mView;
}

glm::mat4 Donut_Camera::getProjectionMat() const
{
    return mProjection;
}
