#include <long_arithmetic.h>

const int PI_PRECISION = 100;

const BigNumber pi_calculation() {
    BigNumber pi("0");
    BigNumber degree_of_16("1");
    BigNumber val_of_8k("0");

    for (int i = 0; i <= PI_PRECISION; i++) {
        BigNumber val1 = BigNumber("4") / (val_of_8k + BigNumber("1"));
        BigNumber val2 = BigNumber("2") / (val_of_8k + BigNumber("4"));
        BigNumber val3 = BigNumber("1") / (val_of_8k + BigNumber("5"));
        BigNumber val4 = BigNumber("1") / (val_of_8k + BigNumber("6"));

        BigNumber val = val1 - val2 - val3 - val4;

        val /= degree_of_16;

        pi += val; 
        val_of_8k += BigNumber("8");
        degree_of_16 *= BigNumber("16");
    }
    
    return pi;
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();
    BigNumber pi = pi_calculation();
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Pi: " << pi.to_string(PI_PRECISION) << std::endl;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    return 0;
}