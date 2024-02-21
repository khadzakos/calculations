#include <long_arithmetic.h>

BigNumber operator "" _f(const char *s) {
    return BigNumber(std::string(s));
}