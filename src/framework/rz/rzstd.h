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

    tMessageType type;
    char const * source_file_location;
    unsigned long identifier;

    cRZStd(tMessageType type, char const * source_file_location, unsigned long identifier) {
        this->type = type;
        this->source_file_location = source_file_location;
        this->identifier = identifier;
    }

    int LogSprintf(char const* kind, long, char const* warning, ...);

private:
    int FromChar(char*);
    static int VSprintf(char const*, ...);
};

void cRZStd_LogAssertText(char const*, long, cRZStd::tMessageType, char*, char*, char*, long, bool);
void cRZStd_DisplayAssertText(void*, char const*, char const*, long);
void cRZStd_DisplayAssertDialog(void*, char const*, char const*, long);