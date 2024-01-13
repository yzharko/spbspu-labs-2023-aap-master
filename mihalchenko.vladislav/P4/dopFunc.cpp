#include "dopFunc.hpp"
#include <iostream>
#include <locale>

bool mihalchenko::ifAlp(char* argv1)
{
  std::locale loc;
  unsigned int c = 0;
  bool fl = true;

  while (argv1[c] && fl)
  {
    if (std::isalpha(argv1[c],loc))
    {
      fl = false;
      break;
    }
    else
    {
      fl = true;
    }
    c++;
  }
  return fl;
}
