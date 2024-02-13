#include <long_arithmetic.h>

const bool BigNumber::is_zero () {
    if (real_size)
        return false;
    return integer_size == 1 && integer_part[0] == 0;
}