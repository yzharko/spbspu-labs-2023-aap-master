#include <limits>
#include <stdexcept>
#include "var1.hpp"

shapar::SequenceCounter::SequenceCounter():
  seqLens(0)
{}

void shapar::SequenceCounter::operator()(int thirdNum)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLens == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
  if (thirdNum == secondNum + firstNum)
    {
      ++count;
    }
  firstNum = secondNum;
  secondNum = thirdNum;
}

size_t shapar::SequenceCounter::operator()() const
{
  return count;
}
