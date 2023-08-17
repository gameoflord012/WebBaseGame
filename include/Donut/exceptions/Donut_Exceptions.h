#ifndef Donut_Exceptions_h
#define Donut_Exceptions_h

#include <iostream>
#include <stdexcept>
#include <fmt/format.h>

#include "Donut/Donut_Log.h"

#define Donut_throw(except) \
    std::cerr << DONUT_COLOR_RED << "[Unhandled Exception]" << DONUT_COLOR_RESET << " at " << __FILE__ << ":" << __LINE__ << "\n"; \
    try { \
        throw except; \
    } \
    catch (const std::exception& e) { \
        std::cerr << "\t" << e.what() << std::endl; \
        std::abort(); \
    }

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