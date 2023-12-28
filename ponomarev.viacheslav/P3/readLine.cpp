#include "readLine.hpp"

char * ponomarev::readLine(std::istream & input)
{
  size_t incremOfEl = 10;
  char * line = new char[incremOfEl]{};
  char elem = 0;
  size_t numOfEl = 0;
  input >> std::noskipws;
  while (std::cin >> elem)
  {
    line[numOfEl++] = elem;
    if (elem == '\n')
    {
      line[numOfEl - 1] = 0;
      break;
    }
    if (numOfEl == incremOfEl)
    {
      char * enlargedArr = new char[numOfEl + incremOfEl]{};
      for (size_t i = 0; i < numOfEl; i++)
      {
        enlargedArr[i] = line[i];
      }
      if (enlargedArr == nullptr)
      {
        delete[] line;
        line = new char[1] {};
        return line;
      }
      delete [] line;
      line = enlargedArr;
    }
  }
  input >> std::skipws;
  return line;
}
