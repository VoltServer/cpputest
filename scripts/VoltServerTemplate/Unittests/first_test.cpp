#include "CppUTest/TestHarness.h"

extern "C" {
#include "code_under_test.h"
}

TEST_GROUP(Foo)
{
void setup() {}
void teardown() {}
};

TEST(Foo, test1)
{
  LONGS_EQUAL(7, Seven());
}

