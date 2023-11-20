#include <limits>
#include <stdexcept>
#include "var2.hpp"

shapar::SequenceCounter_::SequenceCounter_():
  seqLens_(0),
  count_(0),
  secondNum_(0),
  firstNum_(0),
  thirdNum_(0)
{}

void shapar::SequenceCounter_::operator()(int fourthNum_)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLens_ == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
  firstNum_ = secondNum_;
  secondNum_ = thirdNum_;
  thirdNum_ = fourthNum_;
  if ( secondNum_ < firstNum_ && secondNum_ > thirdNum_)
  {
    ++count_;
  }
}

size_t shapar::SequenceCounter_::operator()() const
{
  return count_;
}
