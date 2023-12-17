#include "even_count.hpp"

kovshikov::EvenCount::EvenCount()
{
  count_ = 0;
  max_count_ = 0;
}
void kovshikov::EvenCount::operator()(size_t num)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (count_ == maxSize)
  {
    throw std::logic_error("Sequence is very long\n");
  }
  num % 2 == 0 ? count_ += 1 : count_ = 0;
}
size_t kovshikov::EvenCount::operator()()
{
  max_count_ = (max_count_ > count_ ? max_count_ : count_);
  return max_count_;
}

