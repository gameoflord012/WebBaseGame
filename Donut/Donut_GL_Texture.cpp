#include "Donut/Donut_GL_Texture.h"
#include "Donut/Donut_GL.h"
Donut_GL_Texture::Donut_GL_Texture(const unsigned char *data, int height, int width)
{
    glGenTextures(1, &mId);
    glBindTexture(GL_TEXTURE_2D, mId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    Donut_glCheckErrorAll();
}

Donut_GL_Texture::~Donut_GL_Texture()
{
    glDeleteTextures(1, &mId);
}

// unsigned int texture;
// glGenTextures(1, &texture);
// glBindTexture(GL_TEXTURE_2D, texture);
// // set the texture wrapping/filtering options (on the currently bound texture object)
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// // load and generate the texture
// int width, height, nrChannels;
// unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
// if (data)
// {
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//     glGenerateMipmap(GL_TEXTURE_2D);
// }