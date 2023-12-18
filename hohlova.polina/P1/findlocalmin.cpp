#include <stdexcept>
#include <limits>
#include "findlocalmin.hpp"

hohlovaa::FindLocalMin::FindLocalMin():
  countmins_(0)
{}
void hohlovaa::FindLocalMin::operator()(int prev, int curr, int next)
{
  if (curr < prev && curr < next && next != 0 && curr != 0 && prev != 0)
  {
    ++countmins_;
  }
}
size_t hohlovaa::FindLocalMin::operator()() const
{
  return countmins_;
}
