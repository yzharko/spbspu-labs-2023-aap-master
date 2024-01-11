#include "FindingSubMax.hpp"
#include <stdexcept>
#include <iostream>

khomichenko::FindingSubMax::FindingSubMax():
  subMax_(0),
  max_(0)
{}

void khomichenko::FindingSubMax::operator()(size_t num)
{
  if (num != 0 && num > max_)
  {
    subMax_ = max_;
    max_ = num;
  }
  else if ((num > subMax_) && (num != max_) && (num!=0))
  {
    subMax_ = num;
  }
}

size_t khomichenko::FindingSubMax::operator()() const
{
  return subMax_;
}
