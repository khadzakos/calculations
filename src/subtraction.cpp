#include <long_arithmetic.h>

const BigNumber operator- (const BigNumber &a, const BigNumber &b) {
    BigNumber result;
    short carry = 0;

    result.is_negative = a.is_negative;
    result.real_size = std::max(a.real_size, b.real_size);
    result.real_part.assign(result.real_size, 0);
    for (int i = result.real_size - 1; i >= 0; i--) {
        carry += (i < a.real_size ? a.real_part[i] : 0);
        carry -= (i < b.real_size ? b.real_part[i] : 0);
        if (carry < 0) {
            carry += 10;
            result.real_part[i] = carry;
            carry = -1;
        } else {
            result.real_part[i] = carry;
            carry = 0;
        }
    }

    while (result.real_size) {
        if (!result.real_part.back()) {
            result.real_part.pop_back();
            result.real_size--;
        } else {
            break;
        }
    }
    
    result.integer_size = std::max(a.integer_size, b.integer_size);
    result.integer_part.assign(result.integer_size, 0);
    for (int i = 0; i < result.integer_size; i++) {
        carry += (i < a.integer_size ? a.integer_part[i] : 0);
        carry -= (i < b.integer_size ? b.integer_part[i] : 0);
        if (carry < 0) {
            carry += 10;
            result.integer_part[i] = carry;
            carry = -1;
        } else {
            result.integer_part[i] = carry;
            carry = 0;
        }
    } 

    while (result.integer_size > 1) {
        if (!result.integer_part.back()) {
            result.integer_part.pop_back();
            result.integer_size--;
        } else {
            break;
        }
    }

    return result;
}