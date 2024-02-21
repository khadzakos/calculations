#include <long_arithmetic.h>
#include <gtest/gtest.h>

// Constructor tests

TEST(BigNumber, Constructor1) {
    BigNumber c;

    c = BigNumber("-0000.000");
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "0" << std::endl;

    EXPECT_EQ(c.to_string(), "0");
}

TEST(BigNumber, Constructor2) {
    BigNumber c;

    c = BigNumber("-000000123.00000010000000");
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-123.0000001" << std::endl;

    EXPECT_EQ(c.to_string(), "-123.0000001");
}

TEST(BigNumber, Constructor3) {
    BigNumber c;

    c = BigNumber("123.1424240");
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "123.142424" << std::endl;

    EXPECT_EQ(c.to_string(), "123.142424");
}

// Addition tests

TEST(BigNumber, Addition1) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("-24.000010000000000");
    b = BigNumber("-0125.");
    BigNumber c = a + b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-149.00001" << std::endl;

    EXPECT_EQ(c.to_string(), "-149.00001");
}

TEST(BigNumber, Addition2) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("000123.99876");
    b = BigNumber("054.00124");
    BigNumber c = a + b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "178" << std::endl;

    EXPECT_EQ(c.to_string(), "178");
}

TEST(BigNumber, Addition3) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("98.123");
    b = BigNumber("-99");
    BigNumber c = a + b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-0.877" << std::endl;

    EXPECT_EQ(c.to_string(), "-0.877");
}

TEST(BigNumber, Addition4) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("41");
    b = BigNumber("-5.1");
    BigNumber c = a + b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "35.9" << std::endl;

    EXPECT_EQ(c.to_string(), "35.9");
}

// Subtraction tests

TEST(BigNumber, Subtraction1) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("-293.00000000000000");
    b = BigNumber("-054.00124");
    BigNumber c = a - b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-238.99876" << std::endl;

    EXPECT_EQ(c.to_string(), "-238.99876");
}

TEST(BigNumber, Subtraction2) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("5");
    b = BigNumber("5.00124");
    BigNumber c = a - b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-0.00124" << std::endl;

    EXPECT_EQ(c.to_string(), "-0.00124");
}

TEST(BigNumber, Subtraction3) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("-17.3454");
    b = BigNumber("5");
    BigNumber c = a - b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-22.3454" << std::endl;

    EXPECT_EQ(c.to_string(), "-22.3454");
}

TEST(BigNumber, Subtraction4) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("26");
    b = BigNumber("-5.1");
    BigNumber c = a - b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "31.1" << std::endl;

    EXPECT_EQ(c.to_string(), "31.1");
}

// Multiplication tests

TEST(BigNumber, Multiplication1) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("1.00123");
    b = BigNumber("0.00123");
    BigNumber c = a * b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "0.0012315129" << std::endl;

    EXPECT_EQ(c.to_string(), "0.0012315129");
}

TEST(BigNumber, Multiplication2) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("123.0000");
    b = BigNumber("-54.00124");
    BigNumber c = a * b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "-6642.15252" << std::endl;

    EXPECT_EQ(c.to_string(), "-6642.15252");
}

TEST(BigNumber, Multiplication3) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("0.0000");
    b = BigNumber("0.00124");
    BigNumber c = a * b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "0" << std::endl;

    EXPECT_EQ(c.to_string(), "0");
}

TEST(BigNumber, Multiplication4) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("1234567890");
    b = BigNumber("123456789123456789");
    BigNumber c = a * b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string() << " = " << "152415787654320997501905210" << std::endl;

    EXPECT_EQ(c.to_string(), "152415787654320997501905210");
}

// Division tests

TEST(BigNumber, Division1) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("1.0000123");
    b = BigNumber("0.000123");
    BigNumber c = a / b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string(9) << " = " << "8130.181300813" << std::endl;

    EXPECT_EQ(c.to_string(9), "8130.181300813");
}

TEST(BigNumber, Division2) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("112");
    b = BigNumber("-54.00124");
    BigNumber c = a / b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string(9) << " = " << "-2.074026448" << std::endl;

    EXPECT_EQ(c.to_string(9), "-2.074026448");
}

TEST(BigNumber, Division3) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("1");
    b = BigNumber("3");
    BigNumber c = a / b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string(9) << " = " << "0.333333333" << std::endl;

    EXPECT_EQ(c.to_string(9), "0.333333333");
}

TEST(BigNumber, Division4) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("754");
    b = BigNumber("0.00000645");
    BigNumber c = a / b;
    BigNumber copy_c = c;
    std::cout << copy_c.to_string(9) << " = " << "116899224.806201550" << std::endl;

    EXPECT_EQ(c.to_string(9), "116899224.806201550");
}

// Comparison tests

TEST(BigNumber, Comparison1) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("123.01124");
    b = BigNumber("123.01124");
    std::cout << a.to_string() << " == " << b.to_string() << ": " << (a == b) << std::endl;
    std::cout << a.to_string() << " != " << b.to_string() << ": " << (a != b) << std::endl;
    std::cout << a.to_string() << " < " << b.to_string() << ": " << (a < b) << std::endl;
    std::cout << a.to_string() << " > " << b.to_string() << ": " << (a > b) << std::endl;
    std::cout << a.to_string() << " <= " << b.to_string() << ": " << (a <= b) << std::endl;
    std::cout << a.to_string() << " >= " << b.to_string() << ": " << (a >= b) << std::endl;

    EXPECT_EQ(a == b, true);
    EXPECT_EQ(a != b, false);
    EXPECT_EQ(a < b, false);
    EXPECT_EQ(a > b, false);
    EXPECT_EQ(a <= b, true);
    EXPECT_EQ(a >= b, true);
}

TEST(BigNumber, Comparison2) {
    BigNumber a;
    BigNumber b;

    a = BigNumber("-100.01184");
    b = BigNumber("-100.01124");
    std::cout << a.to_string() << " == " << b.to_string() << ": " << (a == b) << std::endl;
    std::cout << a.to_string() << " != " << b.to_string() << ": " << (a != b) << std::endl;
    std::cout << a.to_string() << " < " << b.to_string() << ": " << (a < b) << std::endl;
    std::cout << a.to_string() << " > " << b.to_string() << ": " << (a > b) << std::endl;
    std::cout << a.to_string() << " <= " << b.to_string() << ": " << (a <= b) << std::endl;
    std::cout << a.to_string() << " >= " << b.to_string() << ": " << (a >= b) << std::endl;

    EXPECT_EQ(a == b, false);
    EXPECT_EQ(a != b, true);
    EXPECT_EQ(a < b, true);
    EXPECT_EQ(a > b, false);
    EXPECT_EQ(a <= b, true);
    EXPECT_EQ(a >= b, false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}