#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cctype>
#include <cstddef>

namespace ponomarev
{
  char * delNums(const char * line, size_t lenLine);
  char * addNums(const char * line, size_t lenLine, const char * secondLine, size_t lenSecLine, size_t incremOfEl);
  char * delDuplic(const char * line, size_t lenLine, const char * thirdLine, size_t lenThirdLine);
};
#endif
