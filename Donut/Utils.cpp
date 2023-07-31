#include "Utils.h"

#include<string>
#include<fstream>
#include<sstream>

#include "Donut/DONUT_Log.h"

std::string DONUT_readfile(std::string filePath)
{
    std::ifstream ifs(filePath);

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    if(buffer.str().empty())
    {
        DONUT_LogWarning("DONUT_readfile read an empty file %s", filePath.c_str());
    }

    return buffer.str();
}

