#include <fmt/format.h>

#include <algorithm>
#include <array>
#include <cmath>
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

void Part1(std::vector<uint64_t>& dists) {
    uint64_t overallDistance(UINT64_MAX);

    uint64_t tmpDistance(0);
    uint64_t indexUsed(0);
    for (uint64_t i = 0; i < dists.size(); i++) {
        tmpDistance = 0;
        for (auto dist : dists) {
            tmpDistance += abs(dist - dists[i]);
        }

        if (tmpDistance < overallDistance) {
            overallDistance = tmpDistance;
            indexUsed = i;
        }
    }

    fmt::print("{} is the position used\n", dists[indexUsed]);
    fmt::print("{} is the overall distance moved.\n", overallDistance);
}

int main(int argc, char** argv) {
    std::vector<uint64_t> numbers;
    readFile(numbers, "input.txt");

    Part1(numbers);
    return 0;
}