#include "rzstd.h"
#include <iostream>

int main(int argc, char **argv)
{

    printf(__FILE__);
    for (int i = 0; i < 200; i++) {
        cRZStd(cRZStd::Error, "WhatTheFuckDidHeSay", __FILE__);
    }
    return 0;
}
