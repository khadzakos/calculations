#include <long_arithmetic.h>

int main() {
    BigNumber a;
    BigNumber b;
    BigNumber c;

    c = BigNumber("-0000.000");
    std::cout << "c: " << c.to_string() << std::endl;

    a = BigNumber("-24.000010000000000");
    b = BigNumber("-0125.");
    c = a + b;
    std::cout << "c = a + b: " << c.to_string() << std::endl;

    a = BigNumber("-123.00000000000000");
    b = BigNumber("-054.00124");
    c = a - b;
    std::cout << "c = a - b: " << c.to_string() << std::endl;

    a = BigNumber("-123.0000");
    b = BigNumber("-054.00124");
    c = a * b;
    std::cout << "c = a * b: " << c.to_string() << std::endl;

    a = BigNumber("1.0000123");
    b = BigNumber("0.000123");
    c = a / b;
    std::cout << "c = a / b: " << c.to_string() << std::endl;
    return 0;
}