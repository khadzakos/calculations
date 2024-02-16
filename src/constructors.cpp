#include <long_arithmetic.h>

const int MAX_FRACTIONAL_SIZE = 250;

BigNumber::BigNumber() {
    is_negative = true;
    number_size = 0;
    point_index = 0;
}

BigNumber::BigNumber (const std::string &str) {
    is_negative = str[0] == '-';
    number = remove_leading_zeros(str.substr(is_negative));
    reverse(number.begin(), number.end());
    number = remove_leading_zeros(number.substr(0));
    point_index = number.find('.');
    number_size = number.size();

    if (point_index == std::string::npos) {
        point_index = number.size();
    }
    
    if (point_index == number_size - 1) {
        number.push_back('0');
    }
    number.erase(point_index, 1);
    number_size = number.size();

    if (is_negative && is_zero()) {
        is_negative = false;
    } 
}

