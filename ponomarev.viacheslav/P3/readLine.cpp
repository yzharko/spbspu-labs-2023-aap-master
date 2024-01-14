#include "readLine.hpp"
#include "incremArr.hpp"

char * ponomarev::readLine(std::istream & input, size_t incremOfEl)
{
  char * line = new char[incremOfEl] {};
  char elem = 0;
  size_t numOfEl = 0;
  size_t limitOfMem = incremOfEl;
  input >> std::noskipws;
  while (std::cin >> elem)
  {
    if (numOfEl == limitOfMem)
    {
      char * enlargedLine = incremArr(line, incremOfEl, numOfEl);
      if (enlargedLine == nullptr)
      {
        delete[] line;
        line = new char[1] {};
        return line;
      }
      limitOfMem += incremOfEl;
      delete[] line;
      line = enlargedLine;
    }
    line[numOfEl] = elem;
    if (elem == '\n')
    {
      line[numOfEl] = 0;
      break;
    }
    numOfEl += 1;
  }
  input >> std::skipws;
  return line;
}
