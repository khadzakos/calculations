#include <long_arithmetic.h>

BigNumber::BigNumber() {
    is_negative = false;
    point_index = 0;
}

BigNumber::BigNumber (const std::string &str, bool flag) {
    is_negative = str[0] == '-';

    int i = is_negative;
    while (i < str.size() && str[i] == '0') {
        if (str[i] == '.') {
            break;
        }
        i++;
    }
    number = str.substr(i);

    if (flag) {
        point_index = number.find('.');
        if (point_index == std::string::npos) {
            number.push_back('.');
            point_index = number.size();
        } else {
            point_index++;
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
    }

    reverse(number.begin(), number.end());
    if (flag) {
        point_index = number.find('.');
        if (point_index + 1 == number.size()) {
            number.push_back('0');
        }
        number.erase(point_index, 1);
    } else {
        point_index = 0;
    }

    if (is_negative && is_zero()) {
        is_negative = false;
    } 
}

