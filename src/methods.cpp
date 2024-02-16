#include <long_arithmetic.h>

const bool BigNumber::is_zero () {
    return number_size == 1 && number[0] == 0;
}

const std::string BigNumber::to_string() {
    std::string str;
    for (int i = 0; i < point_index; i++) {
        str.push_back(number[i]);
    }
    if (point_index > 0) {
        str.push_back('.');
    }
    for (int i = point_index; i < number_size; i++) {
        str.push_back(number[i]);
    }
    reverse(str.begin(), str.end());
    if (is_negative) {
        str.insert(str.begin(), '-');
    }
    return str;
}

const std::string BigNumber::remove_leading_zeros(const std::string &str) {
    int i = 0;
    while (i < str.size() && str[i] == '0') {
        if (str[i] == '.') {
            break;
        }
        i++;
    }
    return str.substr(i);
}

