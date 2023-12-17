#include <limits>
#include <iostream>
#include <stdexcept>
#include "var2.hpp"

shapar::SequenceCounter_::SequenceCounter_():
  seqLens(0),
  count(0)
{}

void shapar::SequenceCounter_::operator()(size_t thirdNum)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLens == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
  if (secondNum < firstNum && secondNum > thirdNum)
  {
    ++count;
  }
  firstNum = secondNum;
  secondNum = thirdNum;
  seqLens += (thirdNum != 0 ? 1 : 0);
}

size_t shapar::SequenceCounter_::operator()() const
{
  return count;
}
