#include <long_arithmetic.h>

const bool BigNumber::is_zero() {
    return std::count(number.begin(), number.end(), '0') == number.size();
}

void BigNumber::remove_leading_zeros() {
    while (number.size() > point_index && number.back() == '0') {
        number.pop_back();
    }
}

const std::string BigNumber::to_string(const int &precision) {
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
    if (is_negative && !is_zero()) {
        str.insert(str.begin(), '-');
    }

    if (precision > -1) {
        int pos = str.find('.');
        if (pos == std::string::npos) {
            str.push_back('.');
            pos = str.size();
        }
        for (int cnt = 0; cnt <= precision; pos++, cnt++) {
            if (pos == str.size()) {
                str.push_back('0');
            }
        }
        while (str.size() > pos) {
            str.pop_back();
        }
    }
    return str;
}


