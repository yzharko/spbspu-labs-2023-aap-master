#include "readLine.hpp"
#include <cstring>
#include "delNums.hpp"

int main()
{
  char * line = ponomarev::readLine(std::cin);
  size_t lenLine = strlen(line);
  if (lenLine == 0)
  {
    std::cerr << "Error, not enough memory\n";
    delete[] line;
    return 1;
  }
  char * resLine = ponomarev::delNums(line, lenLine);
  delete[] line;
  size_t temp = strlen(resLine);
  for (size_t i = 0; i < temp; i++)
  {
    std::cout << resLine[i];
  }
  std::cout << "\n";
  delete[] resLine;
  return 0;
}
