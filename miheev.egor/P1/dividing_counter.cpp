#include "dividing_counter.hpp"
#include <stdexcept>

miheev::DevidingCounter::DevidingCounter(int previous):
  counter_(0),
  seqIsLongEnough_(false),
  previous_(previous)
{}
void miheev::DevidingCounter::checkFirstPrevious() const
{
  if (previous_ == 0)
  {
    throw std::domain_error("Sequence starts with zero, hence it's too short");
  }
}
void miheev::DevidingCounter::operator() (int current)
{
  if (current != 0)
  {
    if (!seqIsLongEnough_)
    {
      seqIsLongEnough_ = true;
    }
    if (current%(previous_) == 0)
    {
      counter_++;
    }
  }
  previous_ = current;
}
size_t miheev::DevidingCounter::getCounter() const
{
  return counter_;
}
bool miheev::DevidingCounter::getIfSeqLongEnough() const
{
  return seqIsLongEnough_;
}
int miheev::DevidingCounter::getPrevious() const
{
  return previous_;
}

