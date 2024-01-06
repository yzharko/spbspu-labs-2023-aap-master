#ifndef READLINE_HPP
#define READLINE_HPP
#include <istream>

namespace hohlova
{
  char* readLine(std::istream& input, size_t& size, size_t& maxCharNum);
  char* extensionOfLine(char* str, char* longerStr, size_t& size, size_t& maxCharNum);
};
#endif

