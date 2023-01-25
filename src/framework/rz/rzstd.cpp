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

cRZStd::cRZStd(cRZStd::tMessageType mtype, const char *message, const char *source_file_location) {
    uint32_t mtype_level = mtype & 15;
    uint32_t mtype_nonsense = mtype_level << 4 | 10;

    char buffer[1024];

    int print_buffer = this->VSprintf(message);

    // well this code seems like nonsense to me.

    if (mtype_level != 8) { // if it isn't an error
        if (mtype_level == 4 || mtype_level == 5) {
            mtype_nonsense << 4 | 2;
            mtype_nonsense = mtype_nonsense;
        }
        if ((mtype_level == 64) || mtype_level == 80 || (mtype_level == 112)) {
            mtype_nonsense = mtype_nonsense | 4;
            mtype_nonsense = mtype_nonsense;
        }
        if ((mtype_level == 0) || mtype_level == 96 || (mtype_level == 16 || (mtype_level == 32))) {
            mtype_nonsense = mtype_nonsense | 1;
        }
    }
    std::cout << "buffer: " << print_buffer << " - source file: " << source_file_location << " - level: " << mtype_level << std::endl;
}

int cRZStd::LogSprintf(const char * message1, long, const char * message2, ...) {
    char buffer [1024];

    if (message2 != nullptr) {
        printf("cRZStd::LogSprintf: Missing RZGetFramework()");
    }
    return 0;
}

int cRZStd::VSprintf(char const* message) {
    char buffer[1024];
    __builtin_va_list args;

    return vsnprintf(buffer, 1024, message, args);
}
