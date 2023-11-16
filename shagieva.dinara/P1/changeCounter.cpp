#include "changeCounter.hpp"
#include <limits>
#include <stdexcept>

shagieva::ChangeCounter::ChangeCounter() :
  lastNumber(0),
  signChange(0)
{}

void shagieva::ChangeCounter::operator()(int number)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  if (signChange > maxSize)
  {
    throw std::logic_error("The number of sign changes is too big.\n");
  }

  if (number * lastNumber < 0)
  {
    ++signChange;
  }

   lastNumber = number;
}

unsigned int shagieva::ChangeCounter::operator()() const
{
  return signChange;
}
