#include "findmaxCountNumbers.hpp"
#include <limits>
#include <stdexcept>

taskaev::findmaxCountNumbers::findmaxCountNumbers() :
  maxCount_(0),
  count_(0),
  previousNum_(0),
  countNum_(0)
{}

void taskaev::findmaxCountNumbers::operator()(int number)
{
  if (maxCount_ == std::numeric_limits< size_t >::max())
  {
    throw std::logic_error("sequence is too long.");
  }
  else {
    if (number == previousNum_) {
      count_++;
    }
    else {
      count_ = 1;
    }
    if (count_ > maxCount_) {
      maxCount_ = count_;
    }
    countNum_ = countNum_ + 1;
    previousNum_ = number;
  }
}
size_t taskaev::findmaxCountNumbers::operator()() const
{
  return maxCount_;
}
