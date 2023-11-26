#include "maxchetn.hpp"
namespace sobolevsky
{
  size_t maxChetn(size_t counter, size_t number)
  {
    (number % 2 == 0 && number != 0) ? counter++ : counter = 0;
    return counter;
  }
}

