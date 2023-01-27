#include "rzgetapp.h"
#include "rzstd.h"
#include <iostream>

int main(int argc, char **argv)
{
    cRZStd std = cRZStd(cRZStd::Error, __FILE__);
    std.LogSprintf("Testing", __LINE__, "this is a test");
    RZGetCurrentAppPath((cIGZString &)"mfw");
    return 0;
}
