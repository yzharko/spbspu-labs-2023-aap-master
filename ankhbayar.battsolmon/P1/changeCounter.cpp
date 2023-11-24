//"changeCounter.hpp"
#include <limits>
#include <stdexcept>

using namespace std;

  std::ChangeCounter::ChangeCounter() :
    lastNumber(0),
    signChange(0)
{}

void std::ChangeCounter::operator()(int number)
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

unsigned int std::ChangeCounter::operator()() const
{
  return signChange;
}
