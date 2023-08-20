#include "Donut/Utils.h"

#include<string>
#include<fstream>
#include<sstream>

#include "Donut/Donut_Log.h"
#include "Donut/Utils.h"

std::string Donut_readfile(std::string filePath)
{
    std::ifstream ifs(filePath);

    Donut_assert(ifs.is_open(), {
        Donut_LogError("file %s doesn't exist", filePath.c_str());
    });

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    ifs.close();

    if(buffer.str().empty())
    {
        Donut_LogWarning("Donut_readfile read an empty file %s", filePath.c_str());
    }

    return buffer.str();
}

std::string Donut_getPath()
{
    return "";
}

std::string Donut_getPath(const std::string& directory,  const std::string& filename)
{
    return directory + filename;
}
