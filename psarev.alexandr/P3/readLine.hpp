#ifndef READ_LINE_HPP
#define READ_LINE_HPP
#include <iostream>

namespace psarev
{
  char* readLine(std::istream& input, size_t extSize, size_t& maxElemNum);
};
#endif
