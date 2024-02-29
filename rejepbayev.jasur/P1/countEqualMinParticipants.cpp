#include "countEqualMinParticipants.hpp"

namespace jasur
{
  MinCounter::MinCounter() : min_value(INT_MAX), count(0) {}
  void MinCounter::process(int value)
  {
    if (value < min_value)
    {
      min_value = value;
      count = 2;
    }
    else if (value == min_value)
    {
      ++count;
    }
  }
  int MinCounter::operator()() const
  {
    return count;
  }
}
