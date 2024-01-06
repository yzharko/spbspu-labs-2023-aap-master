#include "formingString.hpp"

char * taskaev::formingString(const char * string, int & sizeNum, int & newSize)
{
  char * newString = new char[sizeNum + newSize];
  for (int i = 0; i < sizeNum; i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
