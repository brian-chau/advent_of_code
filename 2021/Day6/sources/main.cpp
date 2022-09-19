#include <fmt/format.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void readFile(std::vector<int>& numbers, std::string filename) {
    std::ifstream inFile(filename.c_str());
    std::string line;
    std::getline(inFile, line);
    std::stringstream ss(line);

    for (int i; ss >> i;) {
        numbers.push_back(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }
}

void Part1(std::vector<int>& numbers) {
    std::vector<int> result(numbers);
    for (long unsigned int i = 0; i < numbers.size(); i++) {
        result[i] -= 1;
        if (result[i] < 0) {
            result[i] = 6;
            result.push_back(8);
        }
    }
    numbers.clear();
    for (int i : result) {
        fmt::print("{} ", i);
    }
    fmt::print("\n");
    std::copy(result.begin(), result.end(), std::back_inserter(numbers));
}

void Part2(std::vector<int>& numbers) {
    return;
}

int main() {
    std::vector<int> numbers;
    readFile(numbers, "input.txt");
    unsigned int nDays1(10);
    for (unsigned int i = 0; i < nDays1; i++) {
        Part1(numbers);
    }
    fmt::print("{}\n", numbers.size());
    return 0;
}