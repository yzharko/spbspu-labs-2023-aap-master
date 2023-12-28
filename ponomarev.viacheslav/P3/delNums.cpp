#include "delNums.hpp"

char * ponomarev::delNums(char * line, size_t lenLine)
{
  char * resLine = new char[lenLine] {};
  size_t numOfEl = 0;
  for (size_t i = 0; i < lenLine; i++)
  {
    if (std::isdigit(line[i]) == 0)
    {
      resLine[numOfEl++] = line[i];
    }
  }
  return resLine;
}
