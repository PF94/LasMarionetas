#include "rzstd.h"
#include <iostream>

int main(int argc, char **argv)
{

    printf(__FILE__);
    cRZStd standard = cRZStd(cRZStd::Error, __FILE__, 1337);
    standard.LogSprintf("Testing", 4, "this is a test");
    return 0;
}
