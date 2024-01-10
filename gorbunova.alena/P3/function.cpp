#include "function.hpp"
#include <cctype>

int gorbunova::LatRemove(char *result, char *input, int size)
{
  int s = 0;
  for (int i = 0; i < size; i++)
  {
    if (isalpha(input[i]) == 0)
    {
      result[s++] = input[i];
    }
  }
  return s;
}
