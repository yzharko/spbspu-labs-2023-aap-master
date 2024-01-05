#include "uppLow.hpp"
#include <cctype>

void shagieva::uppLow(const char * inputStr, char * changedStr, const size_t read)
{
  char cur = 0;

  for (size_t i = 0; i < read; i++)
  {
    cur = inputStr[i];
    if (isupper(cur))
    {
      changedStr[i] = tolower(cur);
    }
    else
    {
      changedStr[i] = cur;
    }
  }
}
