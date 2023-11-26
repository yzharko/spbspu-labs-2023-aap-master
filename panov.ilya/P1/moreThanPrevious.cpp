#include "moreThanPrevious.hpp"
panov::MoreThanPrevious::MoreThanPrevious():
  count(0), first(0)
{}

void panov::MoreThanPrevious::operator()(int subsequent)
{
  if (first != 0 && subsequent != 0 && subsequent > first)
  {
    count += 1;
  }
  first = subsequent;
}

size_t panov::MoreThanPrevious::operator()() const
{
  return count;
}
