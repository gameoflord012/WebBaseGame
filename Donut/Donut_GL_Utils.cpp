#include "Donut/Donut_GL_Utils.h"
#include "Donut/Donut_Log.h"

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