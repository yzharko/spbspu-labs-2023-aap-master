#include <cctype>
#include "varFunc.hpp"

int khomichenko::countDifLat ( char * const string)
{
  int marker = 0;
  int count = 0;
  int i = 0;
  const int num = 53;
  char letters[num] = {};
  while (string[i] != '\0')
  {
    if (isalpha(string[i]))
    {
      count = 0;
      for ( int j = 0; j < marker + 1; j++)
      {
        if (letters[j] == string[i])
        {
          ++count;
        }
      }
      if (count == 0)
      {
        letters[marker] = string[i];
        ++marker;
      }
    }
    ++i;
  }
  return marker;
}

void  khomichenko::makingRmvVow (char * const string,char * newString)
{
  int count = 0;
  const char vowel [6] = {'a', 'o', 'u', 'e', 'i', 'y'};
  int marker = 0;
  int i = 0;
  while (string[i] != '\0')
  {
    count = 0;
    for (char j: vowel)
    {
      if (string[i] == j)
      {
        ++count;
      }
    }
    if (count == 0)
    {
      newString[marker] = string[i];
      ++marker;
    }
    ++i;
  }
}
