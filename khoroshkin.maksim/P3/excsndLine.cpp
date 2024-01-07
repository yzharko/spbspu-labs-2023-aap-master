#include "excsndLine.hpp"
#include <cstring>

void khoroshkin::generateNewWithTwo(char * firstLine, const char * secondLine)
{
  size_t length = strlen(firstLine);
  for (size_t i = 0; firstLine[i] != '\0'; ++i)
  {
    bool shouldRemove = false;
    for (size_t j = 0; secondLine[j] != '\0'; ++j)
    {
      shouldRemove = shouldRemove || (firstLine[i] == secondLine[j]);
    }
    if (shouldRemove)
    {
      for (size_t k = i; firstLine[k] != '\0'; ++k)
      {
        firstLine[k] = firstLine[k + 1];
      }
      i--;
      length--;
    }
  }
  firstLine[length] = '\0';
}
