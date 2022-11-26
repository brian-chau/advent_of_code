#include <fmt/format.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void ReadFile(std::vector<int>& datas) {
    std::ifstream in("input.txt");
    std::string line, tmp;
    int val;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, tmp, ',')) {
            std::stringstream(tmp) >> val;
            datas.push_back(val);
        }
    }
}

void Part1() {
    std::vector<int> datas;
    ReadFile(datas);

    int index1(0), index2(0);
    int var1(0), var2(0);
    int storageLocation(0);
    bool stopLoop(false);
    for (size_t i = 0; i < datas.size() && !stopLoop; i += 4) {
        index1 = datas[i + 1];
        index2 = datas[i + 2];
        storageLocation = datas[i + 3];
        var1 = datas[index1];
        var2 = datas[index2];

        switch (datas[i]) {
            case 1:
                datas[storageLocation] = var1 + var2;
                break;
            case 2:
                datas[storageLocation] = var1 * var2;
                break;
            case 99:
                stopLoop = true;
                break;
            default:
                fmt::print("Something went wrong. Detected {}\n", datas[i]);
                break;
        }
    }

    for (auto field : datas) {
        fmt::print("{} ", field);
    }
    fmt::print("\n");
    return;
}

// int Part2() {
//     std::ifstream in("input.txt");
//     std::string line;
//     int mass(0), fuel(0), totalFuel(0);

//     while (std::getline(in, line)) {
//         mass = (int)atoi(line.c_str());
//         do {
//             fuel = mass / 3 - 2;
//             if (fuel > 0) {
//                 totalFuel += fuel;
//                 mass = fuel;
//             }
//         } while (fuel > 0);
//     }
//     return totalFuel;
// }

int main(int argc, char** argv) {
    Part1();
    // std::cout << Part2() << std::endl;
}