#include <long_arithmetic.h>

const int PRECISION = 105;

const BigNumber pi_calculation() {
    BigNumber pi("0", PRECISION);
    BigNumber degree_of_16("1", PRECISION);
    BigNumber val_of_8k("0", PRECISION);

    for (int i = 0; i <= PRECISION; i++) {
        BigNumber val1 = BigNumber("4", PRECISION) / (val_of_8k + BigNumber("1", PRECISION));
        BigNumber val2 = BigNumber("2", PRECISION) / (val_of_8k + BigNumber("4", PRECISION));
        BigNumber val3 = BigNumber("1", PRECISION) / (val_of_8k + BigNumber("5", PRECISION));
        BigNumber val4 = BigNumber("1", PRECISION) / (val_of_8k + BigNumber("6", PRECISION));

        BigNumber val = BigNumber("0", PRECISION);
        val = val1 - val2 - val3 - val4;

        val /= degree_of_16;

        pi += val; 
        val_of_8k += BigNumber("8", PRECISION);
        degree_of_16 *= BigNumber("16", PRECISION);
    }
    
    return pi;
}

int main() {

    auto start = clock();
    BigNumber pi = pi_calculation();
    auto end = clock();

    BigNumber correct_pi = BigNumber("3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196");
    if (pi.to_string(100) == correct_pi.to_string(100)) {
        std::cout << "Pi is correct!" << std::endl;
    } else {
        std::cout << "Fault" << std::endl;
    }
    std::cout << "Pi: " << pi.to_string(100) << std::endl;
    std::cout << "Time: " << (end - start) * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;
    return 0;
}