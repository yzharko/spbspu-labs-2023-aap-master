#include "countSignChange.hpp"
#include <limits>
#include <stdexcept>

ankhbayar::CountSignChange::CountSignChange() :
  lastNumber(0),
  signChange(0)
{}

void ankhbayar::CountSignChange::operator()(int number)
{
  const unsigned int maxSize = std::numeric_limits <unsigned int> ::max();
  if (signChange > maxSize)
  {
    throw std::logic_error("the number of sign changes is too big.\n");
  }

  if (number * lastNumber < 0)
  {
    ++signChange;
  }

  lastNumber = number;
}

unsigned int ankhbayar::CountSignChange::operator()()const
{
  return signChange;
}
