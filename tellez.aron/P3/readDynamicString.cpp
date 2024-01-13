#include "readDynamicString.hpp"
#include <iostream>
#include <cstring>
#include <cstddef>

char* makeNewCapacityCString(const char* cstring, size_t newSize, size_t& newCapacity)
{
  newCapacity = newSize * 2;
  char* newstring = new char[newCapacity];
  std::memcpy(newstring, cstring, newSize);
  return newstring;
}

char* readDynamicString(size_t& size, size_t& capacity)
{
  char* cstring = new char[capacity];
  size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      char* newCString = makeNewCapacityCString(cstring, size, capacity);
      if (newCString == nullptr)
      {
        std::cerr << "Error: Unable to allocate memory for new capacity\n";
        delete[] cstring;
        return nullptr;
      }
      delete[] cstring;
      cstring = newCString;
      newCString = nullptr;
    }
     std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cerr << "Error while reading the string \n";
    delete[] cstring;
    return nullptr;
  }
  return cstring;
}
