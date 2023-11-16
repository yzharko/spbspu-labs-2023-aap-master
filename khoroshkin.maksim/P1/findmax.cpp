#include "findmax.hpp"

khoroshkin::findMax::findMax():
    counter(0), maxValue(std::numeric_limits< int >::min())
  {}

void khoroshkin::findMax::operator()(int Value)
{
  if (maxValue < Value)
  {
    maxValue = Value;
    counter = 0;
    counter++;
  }
  else if (maxValue == Value)
  {
      counter++;
  }
}

int khoroshkin::findMax::operator()()
{
  return counter;
}
