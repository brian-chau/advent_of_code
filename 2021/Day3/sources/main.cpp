#include <gmp.h>
#include <gmpxx.h>

#include <iostream>
#include <memory>

#include "IOHandler.h"
int main() {
    // Load the file
    std::unique_ptr<IOHandler> ioHandler(new IOHandler("input.txt"));
    std::vector<unsigned int> numbers = ioHandler->ReadFile();

    // Implement the algorithm to solve.
    // Problem statement basically describes hamming weights.
    mpz_class gamma(0), eps(0);
    mpz_class numberAcrossLinesAtBit(0);

    // For every bit in each number...
    for (unsigned int bit = 0; bit < ioHandler->BitsPerNumber(); bit++) {
        // (Make room for the next bit)
        gamma <<= 1;
        eps <<= 1;

        // ...create a new number based on the "bit"th bit of each number.
        numberAcrossLinesAtBit = 0;
        for (unsigned int line = 0; line < numbers.size(); line++) {
            numberAcrossLinesAtBit |= (numbers[line] >> (ioHandler->BitsPerNumber() - bit - 1)) & 1;
            numberAcrossLinesAtBit <<= 1;
        }

        // Calculate hamming weight of this new number
        // (i.e. count the number of 1's in the binary representation of the number)
        numberAcrossLinesAtBit = mpz_popcount(numberAcrossLinesAtBit.get_mpz_t());

        if (numberAcrossLinesAtBit > (numbers.size() / 2)) {
            // If the new number has more 1's than 0's, then set the next gamma bit to 1 and leave the next epsillon bit as 0
            gamma |= 1;
        } else {
            // If the new number has more 0's than 1's, then set the next epsillon bit to 1 and leave the next gamma bit as 0
            eps |= 1;
        }
    }

    // Calculate the result per the problem description.
    std::cout << gamma * eps << std::endl;
    return 0;
}
