#include <limits>
#include <iostream>
#include <stdexcept>
#include "var2.hpp"

shapar_::SequenceCounter_::SequenceCounter_():
  seqLens_(0),
  count_(0)
{}

void shapar_::SequenceCounter_::operator()(size_t fourthNum_)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLens_ == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
  firstNum_ = secondNum_;
  secondNum_ = thirdNum_;
  thirdNum_ = fourthNum_;
  if (secondNum_ < firstNum_ && secondNum_ > thirdNum_)
  {
    ++count_;
  }
}

size_t shapar_::SequenceCounter_::operator()() const
{
  return count_;
}
