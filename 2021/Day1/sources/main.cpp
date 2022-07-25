#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>

#include "Queue.h"

unsigned int Part1() {
    std::ifstream infile("input.txt");
    std::string line;

    int prevVal(0);
    unsigned int count(0);
    for (int i = 0; std::getline(infile, line); i++) {
        int curVal(atof(line.c_str()));
        if (i > 0 && curVal > prevVal) {
            count++;
        }
        prevVal = curVal;
    }
    return count;
}

unsigned int Part2() {
    std::ifstream infile("input.txt");
    std::string line;
    FixedQueue<int, 3> q;

    unsigned int count(0);
    int summation(0);
    int prevSummation(0);
    for (int i = 0; std::getline(infile, line); i++) {
        summation += atof(line.c_str());
        if (i >= 3) {
            summation -= q.front();
            if (summation > prevSummation) {
                count++;
            }
            prevSummation = summation;
        }
        q.push(atof(line.c_str()));
    }
    return count;
}

int main() {
    std::cout << Part1() << std::endl;
    std::cout << Part2() << std::endl;
    return 0;
}