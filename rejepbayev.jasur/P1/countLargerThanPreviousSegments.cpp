#include "countLargerThanPreviousSegments.hpp"

namespace jasur
{
  LargerSegmentsCounter::LargerSegmentsCounter():
  count(0), prevElement(0)
  {}
  void LargerSegmentsCounter::operator()(int current)
  {
    if (prevElement != 0 && current != 0 && current > prevElement)
      {
        ++count;
      }
    prevElement = current;
  }
  int LargerSegmentsCounter::operator()() const
  {
    return count;
  }
}
