/**
 * @file
 *
 * @brief RZ's standard library for printing and for asserts, used for errors.
 *
 * @copyright Las Marionetas is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */

#include "rzstd.h"
#include <cstdarg>

int cRZStd::LogSprintf(const char * message1, long, const char * message2, ...)
{
    if (message2 != nullptr) {
        int* framework = nullptr; //RZGetFramework();
    }
    return 0;
}

int cRZStd::VSprintf(char const* message, ...)
{
    int result = 0;
    char buffer[1024];
    va_list va;

    va_start(va, message);
    if (message) {
        result = vsnprintf(buffer, sizeof(buffer), message, va);
    }

    return result;
}
