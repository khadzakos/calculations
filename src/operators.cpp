#include <long_arithmetic.h>

const bool operator== (const BigNumber &a, const BigNumber &b) {
    if (a.is_negative != b.is_negative) {
        return false;
    }
    if (a.number.size() != b.number.size()) {
        return false;
    }

    for (int i = 0; i < a.number.size(); i++) {
        if (a.number[i] != b.number[i]) {
            return false;
        }
    }
    return true;
}

const bool operator!= (const BigNumber &a, const BigNumber &b) {
    return !(a == b);
}

const bool operator< (const BigNumber &a, const BigNumber &b) {
    if (a.is_negative && !b.is_negative) {
        return true;
    }
    if (!a.is_negative && b.is_negative) {
        return false;
    }

    if (!a.is_negative) {
        if (a.number.size() < b.number.size()) {
            return true;
        }
        if (a.number.size() > b.number.size()) {
            return false;
        }
        for (int i = a.number.size() - 1; i >= 0; i--) {
            if (a.number[i] < b.number[i]) {
                return true;
            }
            if (a.number[i] > b.number[i]) {
                return false;
            }
        }
    } else {
        if (a.number.size() > b.number.size()) {
            return true;
        }
        if (a.number.size() < b.number.size()) {
            return false;
        }
        for (int i = a.number.size() - 1; i >= 0; i--) {
            if (a.number[i] > b.number[i]) {
                return true;
            }
            if (a.number[i] < b.number[i]) {
                return false;
            }
        }
    }
    return false;
}

const bool operator<= (const BigNumber &a, const BigNumber &b) {
    return a < b || a == b;
}

const bool operator> (const BigNumber &a, const BigNumber &b) {
    return !(a <= b);
}


const bool operator>= (const BigNumber &a, const BigNumber &b) {
    return a > b || a == b;
}