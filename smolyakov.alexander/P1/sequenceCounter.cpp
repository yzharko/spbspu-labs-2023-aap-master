#include "sequenceCounter.hpp"
#include <cstddef>
#include <limits>
#include <stdexcept>

void SequenceCounter::operator()(const int v)
{
  const size_t maxCount = std::numeric_limits< size_t >::max();
  if (elementsCount_ == maxCount)
  {
    throw std::logic_error("The sequence is too long.");
  }

  if (v != 0)
  {
    elementsCount_++;
    seqEnd_ = seqMid_;
    seqMid_ = seqStart_;
    seqStart_ = v;
    if (validate() && elementsCount_ > 2)
    {
      clear();
      triples_++;
    }
  }
}

int SequenceCounter::operator()() const
{
  if (elementsCount_ < 1)
  {
    throw std::logic_error("The sequence is too short.");
  }
  return triples_;
}

void SequenceCounter::clear()
{
  seqEnd_ = 0;
  seqMid_ = 0;
  seqStart_ = 0;
}

bool SequenceCounter::validate() const
{
  int squares[3];
  squares[0] = seqStart_* seqStart_;
  squares[1] = seqMid_ * seqMid_;
  squares[2] = seqEnd_ * seqEnd_;
  bool c1 = (squares[0] == squares[1] + squares[2]);
  bool c2 = (squares[1] == squares[0] + squares[2]);
  bool c3 = (squares[2] == squares[0] + squares[1]);
  return c1 || c2 || c3;
}
