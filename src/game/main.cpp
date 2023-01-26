#include "rzstd.h"
#include <iostream>

int main(int argc, char **argv)
{

    printf(__FILE__);
    for (int i = 0; i < 200; i++) {
        cRZStd(cRZStd::Error, __FILE__, 1337);
    }
    return 0;
}
