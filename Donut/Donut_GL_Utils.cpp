#include "Donut/Donut_GL_Utils.h"

Donut_GL_Texture * Donut_LoadTexture(const char *path)
{
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

    Donut_GL_Texture * texture = new Donut_GL_Texture(data, height, width);

    delete[] data;

    return texture;
}