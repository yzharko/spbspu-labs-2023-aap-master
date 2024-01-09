#include "getString.hpp"
#include "expandString.hpp"

char * redko::getString(std::istream & in, int & len)
{
  int add = 10;
  char * dest = new char[add];
  char c = ' ';
  in >> std::noskipws;
  while (in >> c && c != '\n')
  {
    dest[len++] = c;
    if (len % add == 0)
    {
      dest = redko::expandString(dest, len);
      if (!dest)
      {
        return nullptr;
      }
    }
  }
  dest[len] = '\0';
  in >> std::skipws;
  return dest;
}
