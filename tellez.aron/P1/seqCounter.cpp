#include "seqCounter.hpp"
#include <limits>
#include <stdexcept>

tellez::LongestDecreasingCounter::LongestDecreasingCounter() :
  current_seq_count(0),
  max_seq_count(0),
  actual(0)
{}

void tellez::LongestDecreasingCounter::processValue(int value)
{
  if (value <= actual)
  {
    current_seq_count++;
    if (current_seq_count > max_seq_count)
    {
      max_seq_count = current_seq_count;
    }
  }
  else
  {
    current_seq_count = 0;
  }
  actual = value;
  const int max_size = std::numeric_limits< int >::max();
  if (max_seq_count == max_size)
  {
    throw std::logic_error("Sequence is too long.");
  }
}

size_t tellez::LongestDecreasingCounter::getLongestSequenceLength() const
{
  return max_seq_count;
}
