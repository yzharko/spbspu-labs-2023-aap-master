#ifndef DIVISIBILITY_HPP
#define DIVISIBILITY_HPP
#include <iostream>

namespace kaseev
{
  class Divisibility
  {
  public:
    Divisibility();
    int operator()(int OldNum, int NewNum);
    void operator()(int count);
  private:
    int count;
    int OldNum;
    int NewNum;
  };
}

#endif