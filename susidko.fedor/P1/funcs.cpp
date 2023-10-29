#include "funcs.h"
#include <iostream>
#include <exception>
#include <limits>

namespace susidko
{
  int read(int second_elem)
  {
    int forth_elem;
    std::cin.exceptions(std::istream::failbit);
    std::cin >> forth_elem;
    if (forth_elem == 0 && second_elem == 0)
    {
      throw std::logic_error("Not enough arguments");
    }
    return forth_elem;
  }

  int getSign(int value)
  {
    return (value > 0) ? 1 : ((value < 0) ? -1 : 0);
  }

  bool isSameSign(int a, int b)
  {
    return getSign(a) * getSign(b) > 0;
  }

  int sum(int a, int b)
  {
    const int max_int = std::numeric_limits< int >::max();
    const int min_int = std::numeric_limits< int >::min();
    if (isSameSign(a, b) && (a > 0))
    {
      if (max_int - a <= b)
      {
        throw std::overflow_error("Signed overflow");
      }
    }
    if (isSameSign(a, b) && (a < 0))
    {
      if (min_int - a >= b)
      {
        throw std::overflow_error("Signed overflow");
      }
    }
    return a + b;
  }
}
