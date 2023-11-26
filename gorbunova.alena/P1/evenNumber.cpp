#include "evenNumber.hpp"
#include <stdexcept>
#include <limits>

gorbunova::EvenNumber::EvenNumber():
  count_(0),
  maxCount_(0)
{}

void gorbunova::EvenNumber::operator()(size_t value)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (count_ == maxSize)
  {
    throw std::logic_error("Too long sequence\n");
  }
  value % 2 == 0 ? count_++ : count_ = 0;
}

size_t gorbunova::EvenNumber::operator()()
{
  maxCount_ = (maxCount_ < count_ ? count_ : maxCount_);
  return maxCount_;
}
