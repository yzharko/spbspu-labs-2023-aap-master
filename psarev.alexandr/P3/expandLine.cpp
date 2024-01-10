#include "expandLine.hpp"

char* psarev::expandLine(char* line, size_t elemNum, size_t extSize)
{
  char* extLine = new char[elemNum + extSize] {};
  for (size_t i = 0; i < elemNum; i++) {
    extLine[i] = line[i];
  }
  return extLine;
}
