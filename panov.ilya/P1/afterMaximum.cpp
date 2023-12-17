#include "afterMaximum.hpp"
#include <limits.h>
panov::AfterMaximum::AfterMaximum():
  count(0), first(0), max_number(INT_MIN)
{}

void panov::AfterMaximum::operator()(int subsequent)
{
  if ((first > max_number))
  {
    max_number = first;
  }
  first = subsequent;
  if ((max_number >= first))
  {
    count++;
    if ((max_number == 0) || (first == 0))
    {
      count -= 1;
    }
  }
}

size_t panov::AfterMaximum::operator()() const
{
  return count;
}
