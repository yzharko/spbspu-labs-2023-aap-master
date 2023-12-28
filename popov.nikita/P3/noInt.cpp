#include "noInt.hpp"
#include <cctype>

void popov::noInt(char * res, char * input, int len)
{
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if (isdigit(input[i]) == 0)
    {
      res[count++] = input[i];
    }
  }
}
