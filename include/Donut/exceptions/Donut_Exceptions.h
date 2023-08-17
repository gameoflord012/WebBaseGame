#ifndef Donut_Exceptions_h
#define Donut_Exceptions_h

#include <iostream>
#include <stdexcept>
#include <fmt/format.h>

#include "Donut/Donut_Log.h"

#define Donut_throw(except, msg) throw except(__FILE__, __LINE__, msg)

namespace Donut
{
    class ExceptionBase : public std::exception {
    public:
        ExceptionBase(const char* message) : errorMessage(message) {}

        const char* what() const noexcept override {
            return errorMessage.c_str();
        }

    private:
        std::string errorMessage;
    };

    class BadValue : public ExceptionBase
    {
    public:
        BadValue(const char* message) : ExceptionBase(message) {}
    };
}

#endif