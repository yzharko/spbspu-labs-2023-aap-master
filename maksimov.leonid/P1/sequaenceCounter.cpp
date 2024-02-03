#include "sequaenceCounter.hpp"
#include <string>

void number::Sequaence::counterSeq()
{
  count++;
  if (count > 2 && secondN < firstN && secondN > thirdN)
  {
    counter++;
  }
}

void number::Sequaence::operator()(int& newN)
{
  firstN = secondN;
  secondN = thirdN;
  thirdN = newN;
}

int number::Sequaence::answer()
{
  if (count < 3)
  {
    throw std::string("not enough number\n");
  }
  return counter;
}
