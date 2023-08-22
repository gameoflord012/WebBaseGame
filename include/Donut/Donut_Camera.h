#ifndef Donut_Camera_h
#define Donut_Camera_h

#include "Donut/Donut_GL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Donut_Camera
{
    public:
        Donut_Camera(glm::vec3 cameraPos, glm::vec3 lookAtPostion);
        glm::mat4 caculateViewMat() const;
        glm::mat4 getProjectionMat() const;
        glm::vec3 caculateCameraUp();
        void setCameraFront(glm::vec3 cameraFront);
        void rotate(float, float);
        void move(float moveRight, float moveUp, float moveForward);
        
    private:
        const glm::vec3 UP_VEC = glm::vec3(0.0f, 1.0f, 0.0f);
        const float CAMERA_FRONT_OFFSET_ANGLE = glm::pi<float>() / 18.;

        glm::mat4 mProjection;
        glm::vec3 mCameraFront;
        glm::vec3 mCameraPos;

        float mYawInRad;
        float mPitchInRad;
};
#endif