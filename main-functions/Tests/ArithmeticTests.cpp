#include "gtest/gtest.h"
#include "../MainFunctions/BaseFunction.h"
#include "../MainFunctions/FuncFactory.h"
#include "../NewOperators.h"


class ArithmeticTests : public ::testing::Test {
public:
    FuncFactory factory;
    shared_ptr<BaseFunction> a, b, c, d, e;

    void SetUp() override {
        a = factory.create("poly", {1, -2, 1});
        b = factory.create("poly", {0, 0, 0, 2});
        c = factory.create("poly", {0, 1, 0});
        d = factory.create("exp", -2);
        e = factory.create("power", -3);
    }
};


TEST_F(ArithmeticTests, SumTests) {
    EXPECT_STREQ((a + b) -> toString().c_str(), "(1-2x+x^2)+(2x^3)");
    EXPECT_STREQ((a + e) -> toString().c_str(), "(1-2x+x^2)+(x^(-3))");
    EXPECT_STREQ((d + e) -> toString().c_str(), "(exp(-2x))+(x^(-3))");

    EXPECT_FLOAT_EQ((*(a+b))(1), 2);
    EXPECT_FLOAT_EQ((*(a+b))(0), 1);
    EXPECT_FLOAT_EQ((*(a+b))(2), 17);

    EXPECT_FLOAT_EQ((a+b)->getDerivativeAtPoint(1), 6);
    EXPECT_FLOAT_EQ((a+b)->getDerivativeAtPoint(0), -2);
    EXPECT_FLOAT_EQ((a+b)->getDerivativeAtPoint(2), 26);

    EXPECT_THROW(a+"abc", logic_error);
    EXPECT_THROW(1 + d, logic_error);
}

TEST_F(ArithmeticTests, ProdAndDivOnlyDerivatives) {
    EXPECT_FLOAT_EQ((c*b)->getDerivativeAtPoint(1), 8);
    EXPECT_FLOAT_EQ((c*b)->getDerivativeAtPoint(0), 0);
    EXPECT_FLOAT_EQ((c*b)->getDerivativeAtPoint(2), 64);

    EXPECT_FLOAT_EQ((b/c)->getDerivativeAtPoint(1), 4);
    EXPECT_THROW((b/c)->getDerivativeAtPoint(0), logic_error);
    EXPECT_FLOAT_EQ((b/c)->getDerivativeAtPoint(2), 8);
}