#include "readLine.hpp"
#include <cstring>
#include "functions.hpp"

int main()
{
  const size_t incremOfEl = 10;
  char * line = ponomarev::readLine(std::cin, incremOfEl);
  const char * secondLine = "g1h2k";
  size_t lenLine = strlen(line);
  size_t lenSecLine = strlen(secondLine);
  if (lenLine == 0)
  {
    std::cerr << "Error, not enough memory\n";
    delete[] line;
    return 1;
  }
  char * lineBefDelNums = ponomarev::delNums(line, lenLine);
  std::cout << lineBefDelNums;
  std::cout << "\n";
  delete[] lineBefDelNums;
  char * lineBefAdNums = ponomarev::addNums(line, lenLine, secondLine, lenSecLine, incremOfEl);
  std::cout << lineBefAdNums;
  std::cout << "\n";
  delete[] lineBefAdNums;
  delete[] line;
  return 0;
}
