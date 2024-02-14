// #TODO DEBUG

#include <long_arithmetic.h>

const bool operator== (const BigNumber &a, const BigNumber &b) {
    if (a.is_negative != b.is_negative)
        return false;
    if (a.integer_size != b.integer_size) {
        return false;
    }
    int size = a.integer_size;
    for (int i = 0; i < size; i++) {
        if (a.integer_part[i] != b.integer_part[i]) {
            return false;
        }
    }
    if (a.real_size != b.real_size) {
        return false;
    }

    size = b.real_size;
    for (int i = 0; i < size; i++) {
        if (a.real_part[i] != b.real_part[i]) {
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
    } else if (!a.is_negative && b.is_negative) {
        return false;
    } else {
        if (!a.is_negative) {
            if (a.integer_size < b.integer_size) {
                return true;
            } else if (a.integer_size > b.integer_size) {
                return false;
            } else {
                int size = a.integer_size;
                for (int i = size - 1; i >= 0; i--) {
                    if (a.integer_part[i] < b.integer_part[i]) {
                        return true;
                    } else if (a.integer_part[i] > b.integer_part[i]) {
                        return false;
                    }
                }
                size = std::max(a.real_size, b.real_size);
                for (int i = 0; i < size; i++) {
                    if ((i < a.real_size ? a.real_part[i] : 0) < (i < b.real_size ? b.real_part[i] : 0)) {
                        return true;
                    } else if ((i < a.real_size ? a.real_part[i] : 0) > (i < b.real_size ? b.real_part[i] : 0)) {
                        return false;
                    }
                }
                return false;
            }
        } else {
            if (a.integer_size > b.integer_size) {
                return true;
            } else if (a.integer_size < b.integer_size) {
                return false;
            } else {
                int size = a.integer_size;
                for (int i = size - 1; i >= 0; i--) {
                    if (a.integer_part[i] > b.integer_part[i]) {
                        return true;
                    } else if (a.integer_part[i] < b.integer_part[i]) {
                        return false;
                    }
                }
                size = std::max(a.real_size, b.real_size);
                for (int i = 0; i < size; i++) {
                    if ((i < a.real_size ? a.real_part[i] : 0) > (i < b.real_size ? b.real_part[i] : 0)) {
                        return true;
                    } else if ((i < a.real_size ? a.real_part[i] : 0) < (i < b.real_size ? b.real_part[i] : 0)) {
                        return false;
                    }
                }
                return false;
            }
        }
    }
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