#include <long_arithmetic.h>

BigNumber::BigNumber() {
    is_negative = true;
    point_index = 0;
}

BigNumber::BigNumber (const std::string &str) {
    is_negative = str[0] == '-';
    number = remove_leading_zeros(str.substr(is_negative));
    point_index = number.find('.');
    if (point_index == std::string::npos) {
        point_index = number.size();
    }
    
    int pos = point_index;
    for (int cnt = 0; cnt < MAX_FRACTIONAL_SIZE; pos++, cnt++) {
        if (pos == number.size()) {
            number.push_back('0');
        }
    }
    while (number.size() > pos) {
        number.pop_back();
    }
    

    reverse(number.begin(), number.end());
    point_index = number.find('.');

    if (point_index == std::string::npos) {
        point_index = number.size();
    }
    
    if (point_index + 1 == number.size()) {
        number.push_back('0');
    }
    number.erase(point_index, 1);

    if (is_negative && is_zero()) {
        is_negative = false;
    } 
}

