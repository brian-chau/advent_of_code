#include <fmt/format.h>

#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void readFile(std::vector<uint64_t>& numbers, std::string filename) {
    std::ifstream inFile(filename.c_str());
    std::string line;
    std::getline(inFile, line);
    std::stringstream ss(line);

    for (uint64_t i; ss >> i;) {
        numbers.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }
}

uint64_t Parts1and2(std::vector<uint64_t>& numbers, uint64_t days) {
// This algorithm counts the number of times each "count" is hit.
// Each count will be hit at least one time, where each count is
// a number from 0 through 8.
#define COUNTS 9
    uint64_t fishes[COUNTS];
    memset(fishes, 0, COUNTS * sizeof(uint64_t));

    for (auto num : numbers) {
        fishes[num]++;
    }

    for (unsigned int day = 0; day < days; day++) {
        uint64_t sum(0);
        for (auto count : fishes) {
            sum += count;
        }

        uint64_t newFishes[COUNTS];
        memset(newFishes, 0, COUNTS * sizeof(uint64_t));
        for (size_t i = 0; i < COUNTS; i++) {
            uint64_t count(fishes[i]);
            if (i == 0) {
                newFishes[6] += count;
                newFishes[8] += count;
            } else {
                newFishes[i - 1] += count;
            }
        }
        for (unsigned int i = 0; i < COUNTS; i++) {
            fishes[i] = newFishes[i];
        }
    }

    uint64_t res(0);
    for (auto count : fishes) {
        res += count;
    }
    return res;
}

int main(int argc, char** argv) {
    std::vector<uint64_t> numbers;
    readFile(numbers, "input.txt");

    std::cout << Parts1and2(numbers, 80) << std::endl;
    std::cout << Parts1and2(numbers, 256) << std::endl;

    return 0;
}