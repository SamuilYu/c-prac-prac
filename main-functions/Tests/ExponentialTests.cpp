#include "gtest/gtest.h"
#include "../MainFunctions/BaseFunction.h"
#include "../MainFunctions/FuncFactory.h"
#include <math.h>


class ExponentialTests : public ::testing::Test {
protected:
    shared_ptr<BaseFunction> a, b, c, d, e, g;
    void SetUp() override {
        FuncFactory factory;
        a = factory.create("exp", 0);
        b = factory.create("exp", {0, 1});
        c = factory.create("exp", {-1, -1, 2, -2, 0, 1});
        d = factory.create("exp", {1, 0, 1});
        e = factory.create("exp", 1.456);
        g = factory.create("exp");
    }
};


TEST_F(ExponentialTests, ToStringTest) {
    EXPECT_STREQ(a->toString().c_str(), "1");
    EXPECT_STREQ(b->toString().c_str(), "1");
    EXPECT_STREQ(c->toString().c_str(), "exp(-x)");
    EXPECT_STREQ(d->toString().c_str(), "exp(x)");
    EXPECT_STREQ(e->toString().c_str(), "exp(1.456x)");
    EXPECT_STREQ(g->toString().c_str(), "1");
}

TEST_F(ExponentialTests, OperatorParenthesesTest) {
    EXPECT_FLOAT_EQ((*a)(0), 1);
    EXPECT_FLOAT_EQ((*a)(-12), 1);
    EXPECT_NEAR((*c)(-12), exp(12), 0.01);
    EXPECT_NEAR((*c)(12), exp(-12), 0.01);
    EXPECT_NEAR((*d)(-12), exp(-12), 0.01);
    EXPECT_NEAR((*d)(12), exp(12), 0.01);
    EXPECT_NEAR((*e)(-1), exp(-1.456), 0.01);
    EXPECT_NEAR((*e)(1), exp(1.456), 0.01);
}