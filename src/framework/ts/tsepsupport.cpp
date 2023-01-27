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
#ifdef WIN32
#include <windows.h>
#include <winreg.h>
#endif

bool TSEPSupport::GetExeNameForHighestInstalledProductFromRegistry(char* executable)
{
   char buffer = 0;
   unsigned long length[4];

   length[0] = 259;
   if (GetAppInfo("Sims2.exe", &buffer, length, nullptr, nullptr, nullptr, nullptr, nullptr)) {
       //todo
   }
}

bool TSEPSupport::GetAppInfo(const char *executable, char *par2, unsigned long *par3, char *par4, unsigned long *par5,
   char *par6, unsigned long *par7, unsigned long *par8)
{
#ifdef WIN32
   PHKEY registry_handler;

   int open_key = RegOpenKeyEx(HKEY_LOCAL_MACHINE, R"(SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths)",
       0, KEY_READ, registry_handler);
   if (open_key == ERROR_SUCCESS) {
#if 0
       if (par2 && par3)
       {
           int open_value = RegQueryValueEx(registry_handler[0], "Game Registry", nullptr, (LPDWORD)executable, reinterpret_cast<LPBYTE>(par2),par3);
           std::clog << open_value << std::endl;
           if (open_value == ERROR_SUCCESS) {
           } else {
               std::cerr << "(TSEPSupport::GetAppInfo) Value failed to open: " << std::system_category().message(open_value)
                         << std::endl;
           }
       }
#else
       std::cerr << "(TSEPSupport::GetAppInfo) Not fully implemented due to Windows stubbornness" << std::endl;
#endif
       RegCloseKey(registry_handler[0]);
   } else {
       std::cerr << "(TSEPSupport::GetAppInfo) Key failed to open: " << std::system_category().message(open_key)
                 << std::endl;
       return false;
   }
#else
   // the mac executable seems to suggest that windows functions were reimplemented for that version so we should do that as well.
   std::cerr << "(TSEPSupport::GetAppInfo) This function currently only works on Windows."
             << std::endl;
   return true;
#endif
}