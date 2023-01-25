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
#pragma once

#include <iostream>

class cRZStd
{

public:
    enum tMessageType: unsigned int {
        Error = 8,
    };

    cRZStd(tMessageType type, char const* message, char const* source_file_location);
    int LogSprintf(char const* message1, long, char const* message2, ...);

private:
    int FromChar(char*);
    void LogAssertText(char const*, long, cRZStd::tMessageType, char*, char*, char*, long, bool);
    void DisplayAssertText(void*, char const*, char const*, long);
    int VSprintf(char const*);
};