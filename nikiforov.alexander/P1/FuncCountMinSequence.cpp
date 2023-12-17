#include "CountMinSequence.hpp"
#include <limits>

nikiforov::Sequence::Sequence() {
  count = 0;
  direction = false;
  max_count = std::numeric_limits< size_t >::max();
  beforvalue = std::numeric_limits< int >::min();
}

void nikiforov::Sequence::operator()(int& value)
{
  if (count > max_count)
  {
    throw std::overflow_error("Too many sequence elements\n");
  }
  if (value < beforvalue) {
    direction = true;
  }
  else if (value > beforvalue && direction == 1 && value != 0) {
    direction = false;
    count++;
  }
  beforvalue = value;
}

size_t nikiforov::Sequence::operator()() {
  return count;
}
