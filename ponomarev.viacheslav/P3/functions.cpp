#include "functions.hpp"
#include "incremArr.hpp"

char * ponomarev::delNums(const char * line, size_t lenLine)
{
  char * lineBefDelNums = new char[lenLine] {};
  size_t numOfEl = 0;
  for (size_t i = 0; i < lenLine; i++)
  {
    if (std::isdigit(line[i]) == 0)
    {
      lineBefDelNums[numOfEl++] = line[i];
    }
  }
  return lineBefDelNums;
}

char * ponomarev::addNums(const char * line, size_t lenLine, const char * secondLine, size_t lenSecLine, size_t incremOfEl)
{
  char * lineBefAdNums = new char[lenLine] {};
  size_t numOfEl = lenLine - 1;
  size_t limitOfMem = lenLine - 1;
  for (size_t i = 0; i < lenLine; i++)
  {
    lineBefAdNums[i] = line[i];
  }
  for (size_t i = 0; i < lenSecLine; i++)
  {
    if (std::isdigit(secondLine[i]) == 1)
    {
      if (numOfEl == limitOfMem)
      {
        char * incremLine = incremArr(lineBefAdNums, incremOfEl, numOfEl);
        limitOfMem += incremOfEl;
        delete[] lineBefAdNums;
        lineBefAdNums = incremLine;
      }
      numOfEl += 1;
      lineBefAdNums[numOfEl] = secondLine[i];
    }
  }
  return lineBefAdNums;
}
