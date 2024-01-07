#include "transformations.hpp"
#include <cctype>

size_t miheev::countDiffLat(char* s)
{
  size_t count = 0;
  for(size_t i = 0; s[i] != '\0'; i++)
  {
    short current = std::tolower(s[i]);
    if (current >= 'a' && current <= 'z')
    {
      count += 1;
      for(size_t j = i + 1; s[j] != '\0'; j++)
      {
        if (s[j] == s[i])
        {
          s[j] = ' ';
        }
      }
      s[i] = ' ';
    }
  }
  return count;
}
