#include "FindEqSeq.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

reznikova::MaxEqualSequense::MaxEqualSequense():
  count(1),
  max_count(0),
  previous_number(0)
{}

void reznikova::MaxEqualSequense::operator()(long long number)
{
  const size_t maximum = std::numeric_limits< size_t >::max();
  if (count <= maximum)
  {
    if (number != previous_number)
    {
      previous_number = number;
      count = 1;
    }
    else
    {
      count++;
    }
    if (count > max_count)
    {
      max_count = count;
    }
  }
  else
  {
    throw std::overflow_error("Too many sequence elements");
  }
}

size_t reznikova::MaxEqualSequense::operator()()
{
  return max_count;
}
