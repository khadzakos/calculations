#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <cassert>

class BigNumber {
    public:
        explicit BigNumber();
        explicit BigNumber(const int &precision);
        explicit BigNumber(const std::string &str_number, const int &precision = 200, bool flag = true);

        friend BigNumber operator- (const BigNumber &a);

        friend BigNumber operator+ (const BigNumber &a, const BigNumber &b);
        friend BigNumber operator- (const BigNumber &a, const BigNumber &b);
        friend BigNumber operator* (const BigNumber &a, const BigNumber &b);
        friend BigNumber operator/ (const BigNumber &a, const BigNumber &b);

        BigNumber &operator+= (const BigNumber &b);
        BigNumber &operator-= (const BigNumber &b);
        BigNumber &operator*= (const BigNumber &b);
        BigNumber &operator/= (const BigNumber &b);

        friend const bool operator== (const BigNumber &a, const BigNumber &b);
        friend const bool operator!= (const BigNumber &a, const BigNumber &b);
        friend const bool operator< (const BigNumber &a, const BigNumber &b);
        friend const bool operator> (const BigNumber &a, const BigNumber &b);
        friend const bool operator<= (const BigNumber &a, const BigNumber &b);
        friend const bool operator>= (const BigNumber &a, const BigNumber &b);

        const std::string to_string(const int &precision = -1);

    private:
        bool is_negative;
        std::string number;
        int point_index;

        const bool is_zero();
        void remove_leading_zeros();

        int MAX_FRACTIONAL_SIZE;
};

BigNumber operator "" _f(const char *s);