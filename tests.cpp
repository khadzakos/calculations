#include <long_arithmetic.h>
#include <gtest/gtest.h>

TEST(Addition, Positive) {
    BigNumber a;
    BigNumber b;
    BigNumber c;

    a = BigNumber("123.00000000000000");
    b = BigNumber("054.00124");
    c = a + b;
    EXPECT_EQ(c.to_string(), "177.00124000000000");

    a = BigNumber("123.0000");
    b = BigNumber("054.00124");
    c = a + b;
    EXPECT_EQ(c.to_string(), "177.00124000000000");

    a = BigNumber("0.0000000000000123");
    b = BigNumber("123");
    c = a + b;
    EXPECT_EQ(c.to_string(), "123.0000000000000123");
}

TEST(Addition, Negative) {
    BigNumber a;
    BigNumber b;
    BigNumber c;

    a = BigNumber("-24.000010000000000");
    b = BigNumber("-0125.");
    c = a + b;
    EXPECT_EQ(c.to_string(), "-149.000010000000000");

    a = BigNumber("-123.00000000000000");
    b = BigNumber("-054.00124");
    c = a + b;
    EXPECT_EQ(c.to_string(), "-177.00124000000000");

    a = BigNumber("-123.0000");
    b = BigNumber("-054.00124");
    c = a + b;
    EXPECT_EQ(c.to_string(), "-177.00124000000000");

    a = BigNumber("-0.0000000000000123");
    b = BigNumber("-123");
    c = a + b;
    EXPECT_EQ(c.to_string(), "-123.0000000000000123");
}

TEST(Subtraction, Positive) {
    BigNumber a;
    BigNumber b;
    BigNumber c;

    a = BigNumber("123.00000000000000");
    b = BigNumber("054.00124");
    c = a - b;
    EXPECT_EQ(c.to_string(), "068.99876000000000");

    a = BigNumber("123.0000");
    b = BigNumber("054.00124");
    c = a - b;
    EXPECT_EQ(c.to_string(), "068.99876000000000");

    a = BigNumber("0.0000000000000123");
    b = BigNumber("123");
    c = a - b;
    EXPECT_EQ(c.to_string(), "-122.9999999999999877");
}

TEST(Division, Positive) {
    BigNumber a;
    BigNumber b;
    BigNumber c;

    a = BigNumber("123.00000000000000");
    b = BigNumber("054.00124");
    c = a / b;
    EXPECT_EQ(c.to_string(), "002.27373600000000");

    a = BigNumber("123.0000");
    b = BigNumber("054.00124");
    c = a / b;
    EXPECT_EQ(c.to_string(), "002.27373600000000");

    a = BigNumber("0.0000000000000123");
    b = BigNumber("0.0000000000000123");
    c = a / b;
    EXPECT_EQ(c.to_string(), "1");
}