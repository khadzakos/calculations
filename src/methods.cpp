#include <long_arithmetic.h>

const bool BigNumber::is_zero () {
    return std::count(number.begin(), number.end(), '0') == number.size();
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

const std::string BigNumber::to_string() {
    std::string str;

    int i = 0;
    while (i < point_index && number[i] == '0') {
        i++;
    }
    point_index -= i;
    number = number.substr(i);

    for (int i = 0; i < point_index; i++) {
        str.push_back(number[i]);
    }
    if (point_index > 0) {
        str.push_back('.');
    }
    for (int i = point_index; i < number.size(); i++) {
        str.push_back(number[i]);
    }
    reverse(str.begin(), str.end());
    if (is_negative) {
        str.insert(str.begin(), '-');
    }
    return str;
}


