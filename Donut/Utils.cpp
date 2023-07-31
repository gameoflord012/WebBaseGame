#include "Utils.h"

#include<string>
#include<fstream>
#include<sstream>

#include "Donut/Donut_Log.h"

std::string Donut_readfile(std::string filePath)
{
    std::ifstream ifs(filePath);

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    if(buffer.str().empty())
    {
        Donut_LogWarning("Donut_readfile read an empty file %s", filePath.c_str());
    }

    return buffer.str();
}

