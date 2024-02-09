#include "getString.hpp"
#include <iostream>
#include "exp.hpp"

char * susidko::getString(std::istream & in)
{
	int len = 0
  int add = 10;
  char * res = new char[add];
  char c = ' ';
  in >> std::noskipws;
  while (in >> c && c != '\n')
  {
    res[len++] = c;
    if (len >= add)
    {
      char * expandedStr = new char[len + add];
      if (!expandedStr)
      {
        return nullptr;
      }
      for (int i = 0; i < len; i++)
      {
        expandedStr[i] = src[i];
      }
      delete[] src;
      res = expandedStr;
      if (!res)
      {
        return nullptr;
      }
    }
  }
  res[len] = '\0';
  in >> std::skipws;
  return res;
}

