#include "savetest.h"
#include "showfirstwordstest.h"
#include "mweftest.h"
#include "mtest.h"
#include "rntest.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
