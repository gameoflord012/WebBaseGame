#include "Utils.h"

#include<string>
#include<fstream>
#include <sstream>

std::string DONUT_readfile(std::string filePath)
{
    std::ifstream ifs(filePath);

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    return buffer.str();
}

