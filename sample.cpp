#include <long_arithmetic.h>

int main() {
    BigNumber a("123456");
    BigNumber b("345678");
    BigNumber c = a - b;
    std::cout << c.to_string() << std::endl;
    return 0;
}