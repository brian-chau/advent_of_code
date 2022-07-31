#include "IOHandler.h"

#include <algorithm>
#include <fstream>

IOHandler::IOHandler(std::string filename)
    : m_Filename(filename)
    , m_NumBits(0) {
}

IOHandler::~IOHandler() {
}

std::vector<unsigned int> IOHandler::ReadFile() {
    std::ifstream inputFile(m_Filename);
    std::string line;
    std::vector<unsigned int> numbers;
    for (unsigned int i = 0; std::getline(inputFile, line); i++) {
        // Remove all whitespaces
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        // Count the number of bits per line
        if (0 == i) {
            m_NumBits = line.size();
        }

        // Convert the number from binary to decimal
        numbers.push_back(std::stoi(line, nullptr, 2));
    }
    return numbers;
}

unsigned int IOHandler::BitsPerNumber() {
    return m_NumBits;
}