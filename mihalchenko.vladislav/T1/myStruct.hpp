#ifndef MYSTRUCT_HPP
#define MYSTRUCT_HPP
#include <iostream>

namespace mihalchenko
{
  struct DinString
  {
  public:
    size_t size = 0;
    char *dinstr = nullptr;
    size_t counterCurrent = 0;
    size_t addArr = 0;

    DinString(size_t n, char c);
    ~DinString();
    void dinResize();
    void dinAppend(char elem);
    void dinOutput();
  };
  size_t findString(char * str1, char * str2, size_t size1, size_t size2);
  size_t stringAnalyz(char * strInput, size_t sizeStrInput);
}
#endif
