#include "rzstd.h"
#include <iostream>

int main(int argc, char **argv)
{
    cRZStd standard = cRZStd(cRZStd::Error, __FILE__, 1337);
    standard.LogSprintf("Testing", __LINE__, "this is a test");
    return 0;
}
