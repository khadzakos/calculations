#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MAX_FRACTIONAL_SIZE = 255;

class BigNumber {
    public:
        explicit BigNumber();
        explicit BigNumber(const std::string &str_number);

        // friend std::istream& operator>> (std::istream &in, BigNumber &number) {
        //     std::string str_number;
        //     in >> str_number;
        //     number = BigNumber(str_number);
        //     return in;
        // }

        // friend std::ostream& operator<< (std::ostream &out, BigNumber &number) {
        // }

        friend const BigNumber operator- (const BigNumber &a);

        friend const BigNumber operator+ (const BigNumber &a, const BigNumber &b);
        friend const BigNumber operator- (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator* (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator/ (const BigNumber &a, const BigNumber &b);

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
        const std::string remove_leading_zeros(const std::string &str);
};