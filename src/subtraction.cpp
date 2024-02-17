#include <long_arithmetic.h>

const BigNumber operator- (const BigNumber &a, const BigNumber &b) {
    if (a.is_negative && b.is_negative) {
        return a + -b;
    }
    if (a.is_negative) {
        return -(-a + b);
    }
    if (b.is_negative) {
        return a + -b;
    }
    if (a < b) {
        return -(b - a);
    }
    BigNumber result;
    result.is_negative = a.is_negative;
    result.point_index = std::max(a.point_index, b.point_index);

    int carry = 0;
    for (int i = 0; i < a.number.size(); i++) {
        int digit = a.number[i] - '0' - carry;
        if (i < b.number.size()) {
            digit -= b.number[i] - '0';
        }
        if (digit < 0) {
            digit += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.number.push_back(digit + '0');
    }

    while (result.number.size() > result.point_index && result.number.back() == '0') {
        result.number.pop_back();
    }

    return result;
}