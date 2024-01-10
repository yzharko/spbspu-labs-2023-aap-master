#include "func.hpp"
#include <iostream>
#include <string.h>

namespace sobolevsky
{
  void changeString(char * str1, char * str2, char * uniqArray, size_t size1, size_t size2)
  {
    for (size_t i = 0; i < size1; i++)
    {
      uniqArray[i] = tolower(str1[i]);
    }

    for (size_t i = 0; i < size2; i++)
    {
      uniqArray[i + size1] = tolower(str2[i]);
    }

    for (size_t m = 0; m < (size1 + size2 + 1); m++)
    {
      for (size_t q = m + 1; q < (size1 + size2 + 1); q++)
      {
        if ((uniqArray[m] == uniqArray[q]) || (uniqArray[q] == ' '))
        {
          uniqArray[q] = 0;
        }
      }
    }

    for(size_t i = 0; i < (size1 + size2); i++)
    {
      for(size_t j = 0; j < (size1 + size2); j++)
      {
        if (static_cast<unsigned char>(uniqArray[j + 1]) < static_cast<unsigned char>(uniqArray[j]))
        {
          std::swap(uniqArray[j + 1], uniqArray[j]);
        }
      }
    }
  }
}
