#include "divCounter.hpp"
#include <limits>
#include <stdexcept>

shagieva::DivCounter::DivCounter() :
  lastNumber(0),
  serialNumber(0),
  count(0)
{}

void shagieva::DivCounter::operator()(int number)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  if (count > maxSize)
  {
    throw std::logic_error("The result is too big.\n");
  }

  ++serialNumber;

  if ((serialNumber != 1) && (number % lastNumber == 0))
  {
    ++count;
  }

  lastNumber = number;
}

unsigned int shagieva::DivCounter::operator()() const
{
  return count;
}
