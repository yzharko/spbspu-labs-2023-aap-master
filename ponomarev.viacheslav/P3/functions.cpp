#include "functions.hpp"
#include "incremArr.hpp"

char * ponomarev::delNums(const char * line, size_t lenLine)
{
  char * lineBefDelNums = new char[lenLine + 1] {};
  size_t numOfEl = 0;
  for (size_t i = 0; i < lenLine; i++)
  {
    if (std::isdigit(line[i]) == 0)
    {
      lineBefDelNums[numOfEl++] = line[i];
    }
  }
  lineBefDelNums[numOfEl] = 0;
  return lineBefDelNums;
}

char * ponomarev::addNums(const char * line, size_t lenLine, const char * secondLine, size_t lenSecLine, size_t incremOfEl)
{
  char * lineBefAdNums = new char[lenLine] {};
  size_t numOfEl = lenLine;
  size_t limitOfMem = lenLine;
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
      lineBefAdNums[numOfEl] = secondLine[i];
      numOfEl += 1;
    }
  }
  lineBefAdNums[numOfEl] = 0;
  return lineBefAdNums;
}

char * ponomarev::delDuplic(const char * line, size_t lenLine, const char * thirdLine, size_t lenThirdLine)
{
  size_t flag = 0;
  size_t numOfEl = 0;
  char * lineBefSort = new char[lenLine + 1] {};
  for (size_t i = 0; i < lenLine; i++)
  {
    for (size_t j = 0; j < lenThirdLine; j++)
    {
      if (line[i] == thirdLine[j])
      {
        flag += 1;
        break;
      }
    }
    if (flag == 0)
    {
      lineBefSort[numOfEl] = line[i];
      numOfEl += 1;
    }
    flag = 0;
  }
  lineBefSort[numOfEl] = 0;
  return lineBefSort;
}








