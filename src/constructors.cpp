#include <long_arithmetic.h>

BigNumber::BigNumber() {
    is_negative = true;
    integer_size = 0;
    real_size = 0;
    number_size = 0;
}

BigNumber::BigNumber (const std::string &str_number) {
    int i = 0;
    int sgn = 0;
    if (str_number[0] == '-') {
        is_negative = true;
        i++;
        sgn++;
    } else {
        is_negative = false;
    }
    for (; i < (int)str_number.size(); i++) {
        if (str_number[i] == '.') {
            break;
        }
    }
    
    for (int j = i - 1; j >= sgn; j--) {
        integer_part.push_back(static_cast<int>(str_number[j] - '0'));
    }
    while (integer_part.size() > 1 && integer_part.back() == 0) {
        integer_part.pop_back();
    }

    for (i++; i < str_number.size(); i++) {
        real_part.push_back(static_cast<int>(str_number[i] - '0'));
    }

    while (real_part.size() && real_part.back() == 0) {
        real_part.pop_back();
    }

    real_size = real_part.size();
    integer_size = integer_part.size();
    number_size = integer_part.size() + real_part.size();

    if (is_negative) {
        if (is_zero()) {
            std::cout << str_number << std::endl;
            is_negative = false;
        }
    }
}

