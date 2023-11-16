#include "minCount.hpp"
#include <limits>
#include <stdexcept>

sukacheva::minCount::minCount():
  count(0),
  min_value(std::numeric_limits< long long > ::max()),
  max_count(std::numeric_limits< long long > ::max())
{}

void sukacheva::minCount::operator()(long long value)
{
  if (count <= max_count)
  {
    if ((value <= min_value) and (value != 0))
    {
      count = value == min_value ? count + 1 : 1;
      min_value = value;
    }
  }
  else
  {
    throw std::overflow_error("Too many elements\n");
  }
}

size_t sukacheva::minCount::operator()() const
{
  return count;
}
