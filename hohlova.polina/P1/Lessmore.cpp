#include <iostream>
#include <stdexcept>
#include "Lessmore.hpp"

hohlova::LessMore::LessMore():
  countres_(0)
{}

void hohlova::LessMore::operator()(int prev, int curr, int next)
{
  if (curr < prev && curr > next && next != 0 && curr != 0 and prev != 0)
  {
    ++countres_;
  }
}
size_t hohlova::LessMore::operator()() const
{
  return countres_;
}
