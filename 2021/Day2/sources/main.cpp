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
    int vert(0);
    for (unsigned int i = 0; std::getline(infile, line); i++) {
        std::stringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);

        if (vstrings[0] == "forward") {
            horiz += atoi(vstrings[1].c_str());
        } else if (vstrings[0] == "up") {
            vert -= atoi(vstrings[1].c_str());
        } else if (vstrings[0] == "down") {
            vert += atoi(vstrings[1].c_str());
        }
    }

    return horiz * vert;
}

int main() {
    std::cout << Part1() << std::endl;
    // std::cout << Part2() << std::endl;
    return 0;
}