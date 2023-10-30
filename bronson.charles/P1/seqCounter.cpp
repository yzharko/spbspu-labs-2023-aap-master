#include "seqCounter.hpp"
#include <limits>
#include <stdexcept>

bronson::SequenceCounter::SequenceCounter():
  seqLength_(0)
{}

void bronson::SequenceCounter::operator()(int number)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (seqLength_ == maxSize)
  {
    throw std::logic_error("Sequence is too long.");
  }
    ++seqLength_;
}

size_t bronson::SequenceCounter::operator()() const
{
  return seqLength_;
}
