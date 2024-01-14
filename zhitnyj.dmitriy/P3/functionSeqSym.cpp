#include "functionSeqSym.h"

size_t strSymbolsRepeats(char* str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    for (size_t j = i + 1; str[j] != '\0'; ++j)
    {
      if (str[i] == str[j])
      {
        return 1;
      }
    }
  }

  return 0;
}
