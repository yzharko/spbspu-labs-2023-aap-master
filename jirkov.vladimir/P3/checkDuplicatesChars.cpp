#include "checkDuplicatesChars.hpp"

int checkDuplicatesChars(const char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == str[i + 1])
    {
      return 1;
    }
  }
  return 0;
}
