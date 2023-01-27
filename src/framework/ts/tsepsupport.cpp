/**
 * @file
 *
 * @brief Class for handling people game expansion packs.
 *
 * @copyright Las Marionetas is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */

#include "tsepsupport.h"
#include "rzstd.h"
#include <iostream>
#include <windows.h>
#include <winreg.h>

bool TSEPSupport::GetExeNameForHighestInstalledProductFromRegistry(char* executable)
{
    char buffer = 0;
    unsigned long length[4];
    if (GetAppInfo("Sims2.exe", &buffer, length, nullptr, nullptr, nullptr, nullptr, nullptr)) {
        //todo
    }
}
bool TSEPSupport::GetAppInfo(const char *executable, char *par1, unsigned long *par2,char *par3, unsigned long *par4,
    char *par5, unsigned long *par6, unsigned long *par7)
{
    PHKEY registry_handler;
    int registry = RegOpenKeyExA(HKEY_LOCAL_MACHINE, R"(SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths)",
        0, 0x20019, registry_handler);
    if (registry == 0) {
        //todo
    } else {
        cRZStd std = cRZStd(cRZStd::Error, __FILE__);
        std.LogSprintf("TSEPSupport", __LINE__, "Registry key failed to open");
        return false;
    }

}
