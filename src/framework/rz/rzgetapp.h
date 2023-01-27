/**
 * @file
 *
 * @brief RZ call functions for application-related things.
 *
 * @copyright Las Marionetas is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */

#pragma once
#include "igzstring.h"

void RZGetCurrentAppPath(cIGZString& string);
void RZGetCurrentAppPath(char*, unsigned long);
void RZGetEnvironmentVariable(char const*, char*, unsigned long);
void RZGetMemoryReport();