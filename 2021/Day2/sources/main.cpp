#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

int Part1() {
    std::ifstream infile("input.txt");
    std::string line;

    unsigned int horiz(0);
    int depth(0);
    for (unsigned int i = 0; std::getline(infile, line); i++) {
        std::stringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);

        if (vstrings[0] == "forward") {
            horiz += atoi(vstrings[1].c_str());
        } else if (vstrings[0] == "up") {
            depth -= atoi(vstrings[1].c_str());
        } else if (vstrings[0] == "down") {
            depth += atoi(vstrings[1].c_str());
        }
    }

    return horiz * depth;
}

int Part2() {
    std::ifstream infile("input.txt");
    std::string line;

    unsigned int horiz(0);
    int depth(0);
    int aim(0);

    for (unsigned int i = 0; std::getline(infile, line); i++) {
        std::stringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);

        if (vstrings[0] == "forward") {
            horiz += atoi(vstrings[1].c_str());
            depth += aim * atoi(vstrings[1].c_str());
        } else if (vstrings[0] == "up") {
            depth -= atoi(vstrings[1].c_str());
            aim -= atoi(vstrings[1].c_str());
        } else if (vstrings[0] == "down") {
            depth += atoi(vstrings[1].c_str());
            aim += atoi(vstrings[1].c_str());
        }
    }

    return horiz * depth;
}

int main() {
    std::cout << Part1() << std::endl;
    std::cout << Part2() << std::endl;
    return 0;
}