#include "countLessThanPrevMoreThanNext.hpp"

namespace jasur
{
  LessMoreCounter::LessMoreCounter() : count(0), prevValue(0), isFirstValue(true) {}

  void LessMoreCounter::process(int value)
  {
    if (!isFirstValue && value != 0)
    {
      if (prevValue > value)
      {
        count++;
      }
    }
    prevValue = value;
    isFirstValue = false;
  }

  int LessMoreCounter::operator()() const
  {
    return count;
  }

}
