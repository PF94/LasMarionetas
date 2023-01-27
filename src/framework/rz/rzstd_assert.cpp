/**
* @file
*
* @brief RZStd's internal functions for asserts.
*
* @copyright Las Marionetas is free software: you can redistribute it and/or
*            modify it under the terms of the GNU General Public License
*            as published by the Free Software Foundation, either version
*            2 of the License, or (at your option) any later version.
*            A full copy of the GNU General Public License can be found in
*            LICENSE
*/

#include "rzstd.h"
#include "rzstring.h"

void cRZStd_LogAssertText(char const* name, long, cRZStd::tMessageType, char* warning, char* va_list, char* source_file,
    long line, bool) {
    std::cout << "cRZStd_LogAssertText: This function requires nGZLog which isn't implemented" << std::endl;
}

void cRZStd_DisplayAssertText(void* something, char const* warning, char const* source_file_location, long line) {
    char* buffer_pointer = const_cast<char *>(warning);
    char buffer[1024];

    if (source_file_location) {
        buffer_pointer = buffer;
        snprintf(buffer_pointer, 1023, "%s (%d): %s", source_file_location, line, warning);
        std::cout << "cRZStd_DisplayAssertText: " << buffer_pointer << std::endl;
    }
}