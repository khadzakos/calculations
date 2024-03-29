#include <long_arithmetic.h>

BigNumber operator*(const BigNumber &a, const BigNumber &b) {
    BigNumber result(a.MAX_FRACTIONAL_SIZE);
    result.is_negative = a.is_negative ^ b.is_negative;
    result.point_index = a.point_index + b.point_index;
    result.number.assign(a.number.size() + b.number.size(), '0');
    
    for (int i = 0; i < a.number.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.number.size(); j++) {
            int digit = (result.number[i + j] - '0') + (a.number[i] - '0') * (b.number[j] - '0') + carry;
            result.number[i + j] = (digit % 10 + '0');
            digit /= 10;
            carry = digit;
        }
        if (carry) {
            result.number[i + b.number.size()] += carry;
        }
    }

    result.remove_leading_zeros();
    if (result.point_index == result.number.size()) {
        result.number.push_back('0');
    }

    int pos = result.point_index;
    for (int cnt = 0; cnt < result.MAX_FRACTIONAL_SIZE; cnt++, pos--);
    result.number = result.number.substr(pos);
    result.point_index = result.MAX_FRACTIONAL_SIZE;

    return result;
}