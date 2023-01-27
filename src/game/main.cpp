#include "rzstd.h"
#include <iostream>

int main(int argc, char **argv)
{
    cRZStd standard = cRZStd(cRZStd::Error, __FILE__, 1337);
    standard.LogSprintf("Testing", 1234, "this is a test");
    return 0;
}
