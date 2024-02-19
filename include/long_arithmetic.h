#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>


const int MAX_FRACTIONAL_SIZE = 255;

class BigNumber {
    public:
        explicit BigNumber();
        explicit BigNumber(const std::string &str_number, bool flag = true);

        friend const BigNumber operator- (const BigNumber &a);

        friend const BigNumber operator+ (const BigNumber &a, const BigNumber &b);
        friend const BigNumber operator- (const BigNumber &a, const BigNumber &b);
        friend const BigNumber operator* (const BigNumber &a, const BigNumber &b);
        friend const BigNumber operator/ (const BigNumber &a, const BigNumber &b);

        friend const bool operator== (const BigNumber &a, const BigNumber &b);
        friend const bool operator!= (const BigNumber &a, const BigNumber &b);
        friend const bool operator< (const BigNumber &a, const BigNumber &b);
        friend const bool operator> (const BigNumber &a, const BigNumber &b);
        friend const bool operator<= (const BigNumber &a, const BigNumber &b);
        friend const bool operator>= (const BigNumber &a, const BigNumber &b);

        const std::string to_string();


    private:
        bool is_negative;
        std::string number;
        int point_index;

        const bool is_zero();
        void remove_leading_zeros();

};