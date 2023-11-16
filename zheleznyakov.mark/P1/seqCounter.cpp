#include "seqCounter.hpp"

zheleznyakov::SequenceCounter::SequenceCounter():
  counter_(0), previousElement_(0)
{}

void zheleznyakov::SequenceCounter::operator()(int current)
{
  if (previousElement_ != 0 && current != 0 && current > previousElement_)
  {
    ++counter_;
  }
  previousElement_ = current;
}

int zheleznyakov::SequenceCounter::operator()() const
{
  return counter_;
}
