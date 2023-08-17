#include "Donut/Donut_Camera.h"
#include "Donut/Donut_GL_Utils.h"
#include "Donut/exceptions/Donut_Exceptions.h"

Donut_Camera::Donut_Camera(glm::vec3 cameraPos, glm::vec3 lookAtPostion)
{
    mCameraPos = cameraPos;
    mCameraFront = lookAtPostion - cameraPos;

    mProjection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

glm::mat4 Donut_Camera::caculateViewMat() const
{
    return glm::lookAt(mCameraPos, mCameraPos + mCameraFront, UP_VEC);
}

glm::mat4 Donut_Camera::getProjectionMat() const
{
    return mProjection;
}

glm::vec3 Donut_Camera::caculateCameraUp()
{
    glm::vec3 cameraRight = glm::cross(mCameraFront, UP_VEC);
    glm::vec3 cameraUp = glm::cross(mCameraFront, cameraRight);
    return glm::normalize(cameraUp);
}

void Donut_Camera::setCameraFront(glm::vec3 cameraFront)
{
    float angle = Donut_getAngle(cameraFront, UP_VEC);

    if(
        angle < CAMERA_FRONT_OFFSET_ANGLE ||
        angle > glm::pi<float>() - CAMERA_FRONT_OFFSET_ANGLE)
    {
        throw Donut::BadValue("Camera font bad position, shouldn't overlap UP_VEC");
    }

    mCameraFront =  glm::normalize(cameraFront);
    //Donut_Log("%f", angle);
}

void Donut_Camera::rotate(float yawInRad, float pitchInRad)
{    
    glm::mat4 rotationMatYaw = glm::rotate(glm::mat4(1.0f), yawInRad, UP_VEC);
    glm::mat4 rotationMatPitch = glm::rotate(glm::mat4(1.0f), pitchInRad, glm::cross(mCameraFront, UP_VEC));

    try {
        setCameraFront(glm::vec3(rotationMatYaw * glm::vec4(mCameraFront, 1.0f)));
    } catch(const std::exception& e) {}

    try {
        setCameraFront(glm::vec3(rotationMatPitch * glm::vec4(mCameraFront, 1.0f)));
    }
    catch(const std::exception& e) {}

    //Donut_Log("%f %f %f", mCameraFront.x, mCameraFront.y, mCameraFront.z);
}
void Donut_Camera::move(float moveRight, float moveUp, float moveForward)
{
    glm::vec3 rightVec = glm::normalize(glm::cross(mCameraFront, UP_VEC));
    glm::vec3 frontVec = glm::normalize(glm::cross(UP_VEC, rightVec));

    mCameraPos += 
        moveUp * UP_VEC +
        moveRight * rightVec +
        moveForward * frontVec;

    //Donut_Log("%f %f %f", mCameraPos.x, mCameraPos.y, mCameraPos.z);
}
