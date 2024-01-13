#include "readLine.hpp"
#include "expandLine.hpp"

char* psarev::readLine(std::istream& input, size_t extSize, size_t& maxElemNum)
{
  size_t elemNum = 0;
  char elem = ' ';
  char* line = new char[maxElemNum] {};
  input >> std::noskipws;

  while (input >> elem) {
    line[elemNum++] = elem;
    if (elem == '\n') {
      line[elemNum - 1] = 0;
      break;
    }
    if (elemNum == maxElemNum) {
      char* expandedLine = expandLine(line, elemNum, extSize);
      if (expandedLine == nullptr) {
        delete[] line;
        line = new char[maxElemNum] {};
        line[0] = 0;
        return line;
      }
      delete[] line;
      line = expandedLine;
      maxElemNum += extSize;
    }
  }
  input >> std::skipws;
  return line;
}
