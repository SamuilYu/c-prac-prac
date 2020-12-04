#include "gtest/gtest.h"
#include "../MainFunctions/BaseFunction.h"
#include "../MainFunctions/FuncFactory.h"

class PolynomialTests: public ::testing::Test {
public:
    shared_ptr<BaseFunction> a, b, c, d, e;
    void SetUp( ) {
        FuncFactory factory;
        a = factory.create("poly", 0);
        b = factory.create("poly", {0, 1});
        c = factory.create("poly", {-1, -1, 2, -2, 0, 1});
        d = factory.create("ident", {1, 0, 1});
        e = factory.create("const", 1.456);
    }

    void TearDown( ) {
        // code to run after each test;
        // can be used instead of a destructor,
        // but exceptions can be handled in this function only
    }

};

TEST_F(PolynomialTests, ToStringTest) {
    EXPECT_STREQ(a->toString().c_str(), "0");
    EXPECT_STREQ(b->toString().c_str(), "x");
    EXPECT_STREQ(c->toString().c_str(), "-1-x+2x^2-2x^3+x^5");
    EXPECT_STREQ(d->toString().c_str(), "x");
    EXPECT_STREQ(e->toString().c_str(), "1.456");
}

TEST_F(PolynomialTests, OperatorParenthesesTest) {
    EXPECT_FLOAT_EQ((*a)(1), 0);
    EXPECT_FLOAT_EQ((*a)(123), 0);
    EXPECT_FLOAT_EQ((*b)(1), 1);
    EXPECT_FLOAT_EQ((*b)(123), 123);
    EXPECT_FLOAT_EQ((*c)(1), -1);
    EXPECT_FLOAT_EQ((*c)(0), -1);
    EXPECT_FLOAT_EQ((*c)(-1), 3);
    EXPECT_FLOAT_EQ((*d)(-1), -1);
    EXPECT_FLOAT_EQ((*d)(-123), -123);
    EXPECT_FLOAT_EQ((*e)(-1), 1.456);
    EXPECT_FLOAT_EQ((*e)(-123), 1.456);
}

TEST_F(PolynomialTests, DerivativesTest) {
    EXPECT_FLOAT_EQ(a->getDerivativeAtPoint(0), 0);
    EXPECT_FLOAT_EQ(a->getDerivativeAtPoint(34), 0);
    EXPECT_FLOAT_EQ(b->getDerivativeAtPoint(34), 1);
    EXPECT_FLOAT_EQ(b->getDerivativeAtPoint(34), 1);
    EXPECT_FLOAT_EQ(c->getDerivativeAtPoint(1), 2);
    EXPECT_FLOAT_EQ(c->getDerivativeAtPoint(0), -1);
    EXPECT_FLOAT_EQ(c->getDerivativeAtPoint(-1), -6);
}