#ifndef MYSTRUCT_HPP
#define MYSTRUCT_HPP
#include <iostream>

namespace mihalchenko
{
  struct DinString
  {
  public:
    DinString(size_t n);
    ~DinString();
    void dinResize();
    void dinAppend(char elem);

    size_t getSize();
    size_t getCounterCurrent();
    char *getDinstr();

  private:
    size_t size_ = 0;
    char *dinstr_ = nullptr;
    size_t counterCurrent_ = 0;
    size_t addArr_ = 0;
  };

  size_t findIdenticalChars(char *str1, char *str2, size_t size1, size_t size2, char *resultStr);

  char *arrUniq(char *mas, size_t size);
}
#endif
