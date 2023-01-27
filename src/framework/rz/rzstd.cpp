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

int cRZStd::LogSprintf(const char * name, long line, const char * warning, ...)
{
    char buffer[1024];
    bool seeminglyAlwaysTrue[13];

    if (warning != nullptr) {
        int* framework = nullptr; //calls RZGetFramework() which isn't implemented yet

        va_list va;
        va_start(va, warning);

        cRZStd_LogAssertText(name, line, this->type,
            (char *)warning, va, (char *)this->source_file_location,
            line, true);

        std::vsnprintf(buffer, sizeof(buffer), warning, va);
        if (framework == nullptr) {
            cRZStd_DisplayAssertText(nullptr, buffer, source_file_location, line);
        } else {
            std::cout << "framework found, but this part of cRZStd::LogSprintf isn't implemented." << std::endl;
        }
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
        result = std::vsnprintf(buffer, sizeof(buffer), message, va);
    }

    return result;
}
