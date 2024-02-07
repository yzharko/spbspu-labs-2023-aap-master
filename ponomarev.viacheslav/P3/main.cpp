#include "readLine.hpp"
#include <cstring>
#include "functions.hpp"

int main()
{
  const size_t incremOfEl = 10;
  const char * line = ponomarev::readLine(std::cin, incremOfEl);
  const char * secondLine = "g1h2k";
  const char * thirdLine = "abc";
  size_t lenLine = strlen(line);
  size_t lenSecLine = strlen(secondLine);
  size_t lenThirdLine = strlen(thirdLine);
  if (lenLine == 0)
  {
    std::cerr << "Error, not enough memory\n";
    delete[] line;
    return 1;
  }
  char * lineBefDelNums = ponomarev::delNums(line, lenLine);
  size_t lenResLine = strlen(lineBefDelNums);
  for (size_t i = 0; i < lenResLine; i++)
  {
    std::cout << lineBefDelNums[i];
  }
  std::cout << "\n";
  delete[] lineBefDelNums;
  char * lineBefAdNums = ponomarev::addNums(line, lenLine, secondLine, lenSecLine, incremOfEl);
  lenResLine = strlen(lineBefAdNums);
  for (size_t i = 0; i < lenResLine; i++)
  {
    std::cout << lineBefAdNums[i];
  }
  std::cout << "\n";
  delete[] lineBefAdNums;
  char * lineBefSort = ponomarev::delDuplic(line, lenLine, thirdLine, lenThirdLine);
  lenResLine = strlen(lineBefSort);
  for (size_t i = 0; i < lenResLine; i++)
  {
    std::cout << lineBefSort[i];
  }
  std::cout << "\n";
  delete[] lineBefSort;
  delete[] line;
  return 0;
}
