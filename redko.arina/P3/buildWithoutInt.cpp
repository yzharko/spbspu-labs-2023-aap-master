#include "buildWithoutInt.hpp"
#include "expandString.hpp"
#include <cctype>
#include <new>

char * redko::buildWithoutInt(char * src, int add)
{
  char * dest = new (std::nothrow) char[add];
  if (!dest)
  {
    return nullptr;
  }
  int i = 0;
  int j = 0;
  while (src[i] != '\0')
  {
    if (isdigit(src[i]) == 0)
    {
      dest[j++] = src[i];
    }
    i++;
    if (j % add == 0)
    {
      dest = redko::expandString(dest, j, add);
      if (!dest)
      {
        return nullptr;
      }
    }
  }
  dest[j] = '\0';
  return dest;
}
