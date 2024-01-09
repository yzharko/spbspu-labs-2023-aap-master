#include "read.hpp"
#include <iostream>
#include "exp.hpp"



char * susidko::getString(std::istream & in, int & len)
{
  int add = 10;
  char * res = new char[add];
  char c = ' ';
  in >> std::noskipws;
  while (in >> c && c != '\n')
  {
    res[len++] = c;
    if (len >= add)
    {
      res = expandString(res, len);
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

