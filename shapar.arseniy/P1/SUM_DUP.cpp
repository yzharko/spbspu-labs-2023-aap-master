#include "SUM_DUP.hpp"
#include <limits>
#include <stdexcept>

shapar::SumdupCounter::SumdupCounter():
  seqLens(0),
  count(0)
{}

void shapar::SumdupCounter::operator()(size_t thirdNum)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLens == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
  if (thirdNum == firstNum + secondNum)
  {
    ++count;
  }
  firstNum = secondNum;
  secondNum = thirdNum;
  seqLens += (thirdNum != 0 ? 1 : 0);
}

size_t shapar::SumdupCounter::operator()() const
{
  if (seqLens < 3)
  {
    throw std::logic_error("Not enough arguments\n");
  }
  else
  {
    return count;
  }
}
