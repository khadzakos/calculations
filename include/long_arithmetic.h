#pragma once

#include <iostream>
#include <vector>
#include <string>

class BigNumber {
    public:
        BigNumber ();
        BigNumber (const std::string &str_number);

        const std::string to_string();

        // friend std::istream& operator>> (std::istream &in, BigNumber &number) {
        //     std::string str_number;
        //     in >> str_number;
        //     number = BigNumber(str_number);
        //     return in;
        // }

        // friend std::ostream& operator<< (std::ostream &out, BigNumber &number) {
        // }

        friend const BigNumber operator+ (const BigNumber &a, const BigNumber &b);
        friend const BigNumber operator- (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator* (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator/ (const BigNumber &a, const BigNumber &b);

        // friend const BigNumber operator== (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator!= (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator< (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator> (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator<= (const BigNumber &a, const BigNumber &b);
        // friend const BigNumber operator>= (const BigNumber &a, const BigNumber &b);


    private:
        bool is_negative;
        std::vector<short> integer_part;
        std::vector<short> real_part;
        int integer_size, real_size, number_size;
};