#include <long_arithmetic.h>

BigNumber &BigNumber::operator+= (const BigNumber &b) {
    *this = *this + b;
    return *this;
}

BigNumber &BigNumber::operator-= (const BigNumber &b) {
    *this = *this - b;
    return *this;
}

BigNumber &BigNumber::operator*= (const BigNumber &b) {
    *this = *this * b;
    return *this;
}

BigNumber &BigNumber::operator/= (const BigNumber &b) {
    *this = *this / b;
    return *this;
}
