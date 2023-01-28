/**
 * @file
 *
 * @brief Implementation of interface for service management and event processing.
 *
 * @copyright Las Marionetas is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */

#include "gzframework.h"
#include <debugapi.h>

void AbortiveQuit(int32_t quit_reason)
{
    OutputDebugStringA("cGZFrameWork::AbortiveQuit()");
    //HookAbortiveQuit(); Not yet implemented.
    OutputDebugStringA("cGZFrameWork::AbortiveQuit(): Calling exit().");
    exit(quit_reason);
}

static void sSetFramework(cGZFrameWork* frameWork)
{
    cGZFrameWork* mpFrameWork = frameWork;
}

#ifndef DLL_EXPORT
cGZFrameWork* RZGetFrameWork()
{
    return cGZFrameWork::mpFrameWork;
}
#endif