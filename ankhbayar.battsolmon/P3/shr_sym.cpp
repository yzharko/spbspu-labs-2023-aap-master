#include "shr_sym.hpp"

void tsomo::missingChar(char* array, char* output, const size_t read)
{
  int element = 0;
  bool flag = false;
  for (int i = 97; i <= 122; i++)
  {
    for (size_t j = 0; j < read; j++)
    {
      if (char(i) == tolower(array[j]))
      {
        flag = true;
      }
      else if ((j == read - 1) && char(i) != tolower(array[j]) && flag == false)
      {
        output[element++] = char(i);
      }
    }
      flag = false;
    }
}
