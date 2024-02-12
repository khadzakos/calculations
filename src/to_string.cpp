#include <long_arithmetic.h>

const std::string BigNumber::to_string() {
    std::string str_number;
    
    //integer part cast
    for (int i = integer_size - 1; i >= 0; i--) {
        str_number += static_cast<char>(integer_part[i] + '0');
    }
    
    //real part cast
    if (real_size) {
        str_number += '.';
        for (int i = 0; i < real_size; i++) {
            str_number += static_cast<char>(real_part[i] + '0');
        }
    }

    return str_number;
}