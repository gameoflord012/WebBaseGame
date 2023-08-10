#ifndef UTILS_H
#define UTILS_H

#include<SDL2/SDL.h>
#include<string>

std::string Donut_readfile(std::string filePath);

std::string Donut_getPath(const std::string& directory, const std::string& filename);

#endif