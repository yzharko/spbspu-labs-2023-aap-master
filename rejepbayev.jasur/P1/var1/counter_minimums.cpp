#include "counter_minimums.hpp"
#include <limits>
#include <stdexcept>

rejepbayev::jasur::CountMinSt::CountMinSt():
  count_(0),
  min(0)
{}
void rejepbayev::jasur::CountMinSt::operator()(int number)
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
size_t rejepbayev::jasur::CountMinSt::operator()()
{
  return count_;
}
