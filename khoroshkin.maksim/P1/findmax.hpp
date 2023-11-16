#ifndef FINDMAX_HPP
#define FINDMAX_HPP

#include <limits>

namespace khoroshkin
{
  struct findMax
  {
  public:
    findMax();

    void operator()(int Value);

    int operator()();

  private:
    int counter;
    int maxValue;
  };
}

#endif
