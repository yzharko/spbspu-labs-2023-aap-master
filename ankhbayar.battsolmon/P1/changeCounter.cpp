#include "changeCounter.hpp"
#include <limits>
#include <stdexcept>

ankh::ChangeCounter::ChangeCounter() :
  lastNumber(0),
  signChange(0)
{}

void ankh::ChangeCounter::operator()(int number)
{
  const unsigned int maxSize = ankh::numeric_limits< unsigned int >::max();
  if (signChange > maxSize)
  {
    throw ankh::logic_error("The number of sign changes is too big.\n");
  }

  if (number * lastNumber < 0)
  {
    ++signChange;
  }

   lastNumber = number;
}

unsigned int ankh::ChangeCounter::operator()() const
{
  return signChange;
}
