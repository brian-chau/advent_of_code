#include <fstream>
#include <iostream>
#include <string>

int Part1(){
    std::ifstream in("input.txt");
    std::string line;
    int fuel(0);

    while (std::getline(in, line)) {
        fuel += (int)atoi(line.c_str()) / 3 - 2;
    }
    return fuel;
}

int Part2(){
    std::ifstream in("input.txt");
    std::string line;
    int mass(0), fuel(0), totalFuel(0);

    while (std::getline(in, line)) {
        mass = (int)atoi(line.c_str());
        do {
            fuel = mass / 3 - 2;
            if (fuel > 0) {
                totalFuel += fuel;
                mass = fuel;
            }
        } while (fuel > 0);
    }
    return totalFuel;
}

int main(int argc, char** argv) {
    std::cout << Part1() << std::endl;
    std::cout << Part2() << std::endl;
}