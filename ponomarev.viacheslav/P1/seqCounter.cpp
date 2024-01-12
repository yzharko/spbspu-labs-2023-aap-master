#include "seqCounter.hpp"
#include <limits>
#include <stdexcept>

ponomarev::SequenceCounter::SequenceCounter():
  seqLength_(0),
  firstNum_(0),
  secondNum_(0),
  countLocmax_(0)
  {}

void ponomarev::SequenceCounter::operator()(size_t number)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLength_ == maxSize)
  {
    throw std::logic_error("Sequence is too long.\n");
  }
  seqLength_ += (number != 0 ? 1 : 0);
  countLocmax_ += (secondNum_ > firstNum_ ? secondNum_ > number ? 1 : 0 : 0);
  firstNum_ = secondNum_;
  secondNum_ = number;
}

size_t ponomarev::SequenceCounter::operator()() const
{
  if (seqLength_ < 3)
  {
    throw std::logic_error("Sequence is too small\n");
  }
  else
  {
    return countLocmax_;
  }
}
