#include <gmp.h>
#include <gmpxx.h>

#include <cmath>
#include <iostream>
#include <memory>

#include "IOHandler.h"

mpz_class Part1() {
    // Load the file
    std::unique_ptr<IOHandler> ioHandler(new IOHandler("input.txt"));
    std::vector<unsigned int> inputNumbers = ioHandler->ReadFile();

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
        for (unsigned int lineIndex = 0; lineIndex < inputNumbers.size(); lineIndex++) {
            numberAcrossLinesAtBit |= (inputNumbers[lineIndex] >> (ioHandler->BitsPerNumber() - bit - 1)) & 1;
            numberAcrossLinesAtBit <<= 1;
        }

        // Calculate hamming weight of this new number
        // (i.e. count the number of 1's in the binary representation of the number)
        numberAcrossLinesAtBit = mpz_popcount(numberAcrossLinesAtBit.get_mpz_t());

        if (numberAcrossLinesAtBit >= (inputNumbers.size() / 2)) {
            // If the new number has more 1's than 0's, then set the next gamma bit to
            // 1 and leave the next epsillon bit as 0
            gamma |= 1;
        } else {
            // If the new number has more 0's than 1's, then set the next epsillon bit
            // to 1 and leave the next gamma bit as 0
            eps |= 1;
        }
    }

    // Calculate the result per the problem description.
    return gamma * eps;
}

unsigned int Part2_sub(std::vector<unsigned int>& diagnostics, unsigned int bitsPerNumber, bool useMostCommonBit) {
    std::vector<unsigned int> localDiagnostics(diagnostics);
    std::vector<unsigned int> tmpDiagnostics;

    // For every bit in each number...
    for (unsigned int bitIndex = 0; bitIndex < bitsPerNumber; bitIndex++) {
        if (localDiagnostics.size() == 1) {
            break;
        }

        // ...create a new number based on the "bit"th bit of each number.
        mpz_class numberAcrossLinesAtBit(0);
        for (unsigned int lineIndex = 0; lineIndex < localDiagnostics.size(); lineIndex++) {
            numberAcrossLinesAtBit |= (localDiagnostics[lineIndex] >> (bitsPerNumber - bitIndex - 1)) & 1;
            numberAcrossLinesAtBit <<= 1;
        }

        // Calculate hamming weight of this new number
        // (i.e. count the number of 1's in the binary representation of the number)
        mpz_class hammingWeight = mpz_popcount(numberAcrossLinesAtBit.get_mpz_t());
        unsigned int commonBit(0);
        if (useMostCommonBit) {
            commonBit = (hammingWeight >= (localDiagnostics.size() / 2) ? 1 : 0);
        } else {
            commonBit = (hammingWeight >= (localDiagnostics.size() / 2) ? 0 : 1);
        }

        tmpDiagnostics.clear();
        for (unsigned int entryIndex = 0; entryIndex < localDiagnostics.size(); entryIndex++) {
            unsigned int entry = localDiagnostics[entryIndex];
            if ((entry >> (bitsPerNumber - bitIndex - 1) & 1) == commonBit) {
                tmpDiagnostics.push_back(entry);
            }
        }
        localDiagnostics.clear();
        localDiagnostics = tmpDiagnostics;
    }
    return localDiagnostics[0];
}

mpz_class Part2() {
    // Load the file
    std::unique_ptr<IOHandler> ioHandler(new IOHandler("input.txt"));
    std::vector<unsigned int> inputNumbers = ioHandler->ReadFile();

    // Implement the algorithm to solve.
    // Problem statement basically describes hamming weights.
    mpz_class lifeSupportRating(0);
    unsigned int o2Rating = Part2_sub(inputNumbers, ioHandler->BitsPerNumber(), true);
    unsigned int co2Rating = Part2_sub(inputNumbers, ioHandler->BitsPerNumber(), false);

    // Calculate the result per the problem description.
    lifeSupportRating = o2Rating * co2Rating;
    return lifeSupportRating;
}

int main() {
    std::cout << Part1() << std::endl;
    std::cout << Part2() << std::endl;
    return 0;
}
