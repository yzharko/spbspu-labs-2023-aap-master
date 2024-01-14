#include "newarr.hpp"
#include "delzero.hpp"

char* newarr(std::istream& in, size_t& sizeStr)
{
  size_t lenStr = 10;
  char* str = new char[lenStr]{};
  char temp = 0;
  size_t dataIndex = 0;
  in >> std::noskipws;
  while (in >> temp && temp != '\n')
  {
    if (++dataIndex < lenStr - 1)
    {
      str[dataIndex] = temp;
    }
    else
    {
      str[dataIndex] = temp;
      lenStr *= 2;
      char* newStr = new char[lenStr]{};
      for (size_t i = 0; i < lenStr / 2; i++)
      {
        newStr[i] = str[i];
      }
      delete[] str;
      str = newStr;
    }
  }
  if (temp == 0)
  {
    delete[] str;
    throw std::exception();
  }
  in >> std::skipws;
  str = delzero(str, lenStr);
  sizeStr = lenStr;
  return str;
}
