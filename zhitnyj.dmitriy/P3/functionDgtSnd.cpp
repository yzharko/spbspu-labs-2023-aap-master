#include "functionDgtSnd.h"
#include <iostream>
#include <cctype>

char* appendNumToStr(char* str1, char* str2)
{
  size_t BUFFER_SIZE = 100;
  char* dest = new char[BUFFER_SIZE];
  size_t capacity = BUFFER_SIZE;
  size_t size = 0;

  while (*str1)
  {
    if (size >= capacity - 1)
    {
      capacity *= 2;
      char* newBuffer = new char[capacity];
      std::memcpy(newBuffer, dest, size);
      delete[] dest;
      dest = newBuffer;
    }
    dest[size++] = *str1++;
  }

  while (*str2)
  {
    if (std::isdigit(*str2))
    {
      if (size >= capacity - 1)
      {
        capacity *= 2;
        char* newBuffer = new char[capacity];
        std::memcpy(newBuffer, dest, size);
        delete[] dest;
        dest = newBuffer;
      }
      dest[size++] = *str2;
    }
    ++str2;
  }

  if (size >= capacity)
  {
    capacity += 1;
    char* newBuffer = new char[capacity];
    std::memcpy(newBuffer, dest, size);
    delete[] dest;
    dest = newBuffer;
  }
  dest[size] = '\0';

  return dest;
}
