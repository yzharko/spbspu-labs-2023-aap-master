#include "neostring.hpp"
#include <iostream>
#include <iomanip>

namespace miheev
{
  size_t readString(char** receiver, std::istream& stream)
  {
    size_t receiverSize = 0;
    if (*receiver != nullptr)
    {
      while (*(*receiver + receiverSize) != '\0')
      {
        receiverSize++;
      }
    }
    const size_t additionalSize = 5;
    stream >> std::noskipws;
    char c = 0;
    size_t firstFree = 0;
    while (stream >> c) // may crush
    {
      if (firstFree >= receiverSize)
      {
        char* temp = new char[receiverSize + additionalSize]{};
        for (size_t i = 0; i < receiverSize; i++)
        {
          temp[i] = *(*receiver + i);
        }
        delete[] *receiver;
        *receiver = temp;
        receiverSize += additionalSize;
        temp = nullptr;
      }
      if (c == '\n')
      {
        *(*receiver + firstFree) = 0;
        break;
      }
      *(*receiver + firstFree++) = c;
    }
    if (*receiver == nullptr or firstFree == 0)
    {
      return 0;
    }
    stream >> std::skipws;
    return firstFree - 1;
  }
}
