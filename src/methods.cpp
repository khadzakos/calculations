#include <long_arithmetic.h>

const bool BigNumber::is_zero () {
    return std::count(number.begin(), number.end(), '0') == number.size();
}

void BigNumber::remove_leading_zeros() {
    while (number.size() > point_index && number.back() == '0') {
        number.pop_back();
    }
}

const std::string BigNumber::to_string() {
    std::string str;
    std::string copy_number = number;

    int i = 0;
    while (i < point_index && copy_number[i] == '0') {
        i++;
    }
    point_index -= i;
    copy_number = copy_number.substr(i);

    for (int i = 0; i < point_index; i++) {
        str.push_back(copy_number[i]);
    }
    if (point_index > 0) {
        str.push_back('.');
    }
    for (int i = point_index; i < copy_number.size(); i++) {
        str.push_back(copy_number[i]);
    }
    reverse(str.begin(), str.end());
    if (is_negative && !is_zero()) {
        str.insert(str.begin(), '-');
    }
    return str;
}


