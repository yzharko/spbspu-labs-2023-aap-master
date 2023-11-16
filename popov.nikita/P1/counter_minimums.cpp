#include "counter_minimums.hpp"
#include <limits>
#include <stdexcept>

popov::CountMinSt::CountMinSt():
  count_(0),
  min(0)
{}
void popov::CountMinSt::operator()(int number)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (min == 0)
  {
    min = number;
  }
  if (number == min)
  {
    if (count_ == maxSize)
    {
      throw std::logic_error("Count is too much.");
    }
    ++count_;
  }
  else if (min > number)
  {
    count_ = 1;
    min = number;
  }
}
size_t popov::CountMinSt::operator()()
{
  return count_;
}
