#include "findingCount.hpp"
#include <iostream>
#include <stdexcept>

doroshenko::FindingCount::FindingCount():
  countNums_(0),
  countSum_(0),
  firstNum_(0),
  secondNum_(0)
{}

void doroshenko::FindingCount::operator()(size_t value)
{
  countNums_ += (value != 0 ? 1 : 0);
  countSum_ += (value == firstNum_ + secondNum_ ? 1 : 0);
  firstNum_ = secondNum_;
  secondNum_ = value;
}

size_t doroshenko::FindingCount::operator()() const
{
  if (countNums_ < 3)
  {
    throw std::logic_error("Too short sequence\n");
  }
  else
  {
    return countSum_;
  }
}
