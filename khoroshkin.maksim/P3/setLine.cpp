#include "setLine.hpp"

char * khoroshkin::inputLine(std::istream & input, size_t & userStringLength, size_t userAddSize)
{
  char * line = new char[userAddSize];
  char c = 0;
  input >> std::noskipws;
  while (input >> c)
  {
    if (userStringLength == userAddSize - 1)
    {
      userAddSize += userAddSize;
      char * newLine = new char[userAddSize];
      for (size_t i = 0; i < userStringLength; i++)
      {
        newLine[i] = line[i];
      }
      delete[] line;
      line = newLine;
    }
    line[userStringLength++] = c;
    if (userStringLength == userAddSize - 1 || c == '\n')
    {
      line[userStringLength] = '\0';
      break;
    }
  }
  return line;
}
