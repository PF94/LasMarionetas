#include <gtest/gtest.h>
#include <rz/rzstd.h>


TEST(std, message_type)
{
    for (int i = 0; i < 100; ++i) {
        cRZStd(i, "12345678", 8);
    }
}