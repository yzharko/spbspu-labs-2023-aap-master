#include "getString.hpp"
#include "expandString.hpp"
#include <iostream>
#include <new>

char * redko::getString(int & len, const int add)
{
  char * dest = new (std::nothrow) char[add];
  char c = ' ';
  std::cin >> std::noskipws;
  while (std::cin >> c && c != '\n')
  {
    dest[len++] = c;
    if (len % add == 0)
    {
      dest = redko::expandString(dest, len, add);
      if (!dest)
      {
        return nullptr;
      }
    }
  }
  dest[len] = '\0';
  std::cin >> std::skipws;
  return dest;
}
