#include "Donut/Donut_GL_Utils.h"
#include "Donut/Donut_Log.h"
#include <glm/glm.hpp>

Donut_GL_Texture * Donut_LoadTexture(const char *path)
{
    int width, height, nrChannels;
    
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

    Donut_assert(data, 
    {
        Donut_LogError("No texture found in %s", path);
    });

    Donut_GL_Texture * texture = new Donut_GL_Texture(data, width, height, nrChannels);

    stbi_image_free(data);

    return texture;
}

float Donut_getAngle(glm::vec3 v1, glm::vec3 v2)
{
    float dotProduct = glm::dot(v1, v2);
    float magnitudeA = glm::length(v1);
    float magnitudeB = glm::length(v2);
    
    float cosTheta = dotProduct / (magnitudeA * magnitudeB);
    return std::acos(cosTheta);
}