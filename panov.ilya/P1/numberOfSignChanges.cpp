#include "numberOfSignChanges.hpp"
panov::NumberOfSignChanges::NumberOfSignChanges():
  count(0), first(0)
{}

void panov::NumberOfSignChanges::operator()(int subsequent)
{
  if ((first < 0 && subsequent > 0) || (first > 0 && subsequent < 0))
  {
    count += 1;
  }
  first = subsequent;
}

size_t panov::NumberOfSignChanges::operator()() const
{
  return count;
}
