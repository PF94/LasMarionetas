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

#include "rzgetapp.h"
#include "tsepsupport.h"

void RZGetCurrentAppPath(cIGZString& string)
{
    char executable[257];
    TSEPSupport::GetExeNameForHighestInstalledProductFromRegistry(executable);
}