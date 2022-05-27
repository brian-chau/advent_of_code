#ifndef IOHANDLER_H
#define IOHANDLER_H
#include <string>
#include <vector>

class IOHandler {
   public:
    IOHandler(std::string filename);
    ~IOHandler();
    std::vector<unsigned int> ReadFile();
    unsigned int BitsPerNumber();

   private:
    std::string m_Filename;
    unsigned int m_NumBits;
};
#endif