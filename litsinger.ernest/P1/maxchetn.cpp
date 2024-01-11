#include "maxchetn.hpp"

litsinger::countMax::countMax():
  counter(0),
  max(0)
{}

void litsinger::countMax::operator()(int value)
{
  if (max == 0)
  {
    max = value;
  }
  if (value == max)
  {
    counter++;
  }
  else if (max < value)
  {
    counter = 1;
    max = value;
  }
}
size_t litsinger::countMax::operator()()
{
  return counter;
}
