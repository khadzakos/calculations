#include <long_arithmetic.h>

const BigNumber operator/ (const BigNumber &a, const BigNumber &b) {
    BigNumber copy_a = a;
    BigNumber copy_b = b;
    copy_a.point_index = 0;
    copy_b.point_index = 0;
    copy_a.is_negative = false;
    copy_b.is_negative = false;
    copy_a.remove_leading_zeros();
    copy_b.remove_leading_zeros();

    if (copy_b.is_zero()) {
        throw std::runtime_error("Division by zero");
    }
    if (copy_a.is_zero()) {
        return BigNumber("0");
    }
    BigNumber result;
    result.is_negative = copy_a.is_negative ^ copy_b.is_negative;
    
    while (copy_a >= copy_b) {
        std::string temp_str;
        while (!copy_a.number.empty() && temp_str.size() < copy_b.number.size()) {
            temp_str.push_back(copy_a.number.back());
            copy_a.number.pop_back();
        }

        BigNumber temp(temp_str, false);
        if (temp < copy_b) {
            if (copy_a.number.empty()) {
                break;
            } else {
                temp_str.push_back(copy_a.number.back());
                copy_a.number.pop_back();
                temp = BigNumber(temp_str, false);
            } 
        }

        int digit = 0;
        while (temp >= copy_b) {
            temp = temp - copy_b;
            temp.remove_leading_zeros();
            digit++;
            if (digit > 9) {
                break;
            }
        }
        result.number.push_back(digit + '0');

        temp.remove_leading_zeros();
        if (temp.is_zero()) {
            while (!copy_a.number.empty() && copy_a.number.back() == '0') {
                copy_a.number.pop_back();
                result.number.push_back('0');
            }
            break;
        }
        copy_a.number += temp.number;
    }

    if (result.number.empty()) {
        result.number.push_back('0');
    }
    result.point_index = result.number.size();
    int after_point = 0;
    while (after_point < MAX_FRACTIONAL_SIZE) {
        if (copy_a.number.empty()) {
            result.number.push_back('0');
            after_point++;
            continue;
        }

        bool flag = 0;
        while (copy_a.number.size() < copy_b.number.size()) {
            copy_a.number = copy_a.number.insert(0, "0");
            if (flag) {
                result.number.push_back('0');
                after_point++;
                if (after_point >= MAX_FRACTIONAL_SIZE) {
                    break;
                }
            }
            flag = 1;
        }
        if (after_point >= MAX_FRACTIONAL_SIZE) {
            break;
        } 
        
        if (copy_a < copy_b) {
            copy_a.number = copy_a.number.insert(0, "0");
            if (flag) {
                result.number.push_back('0');
                after_point++;
            }
            flag = 1;
        }
        if (after_point >= MAX_FRACTIONAL_SIZE) {
            break;
        }

        int digit = 0;
        while (copy_a >= copy_b) {
            copy_a = copy_a - copy_b;
            copy_a.remove_leading_zeros();
            digit++;
            if (digit > 9) {
                break;
            }
        }
        
        if (digit >= 10) {
            std::cout << "after_point: " << after_point << std::endl;
        }
        assert(digit < 10); 
        result.number.push_back(digit + '0');
        after_point++;
        copy_a.remove_leading_zeros();
    }

    reverse(result.number.begin(), result.number.end());
    result.point_index = result.number.size() - result.point_index;
    return result;
}