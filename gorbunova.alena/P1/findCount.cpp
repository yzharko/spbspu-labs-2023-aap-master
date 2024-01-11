#include "findCount.hpp"
#include <stdexcept>

gorbunova::FindCount::FindCount():
  countNumbers_(0),
  countSum_(0),
  firstNumber_(0),
  secondNumber_(0)
{}

void gorbunova::FindCount::operator()(size_t value)
{
  countNumbers_ += (value != 0 ? 1 : 0);
  countSum_ += (value == firstNumber_ + secondNumber_ ? 1 : 0);
  firstNumber_ = secondNumber_;
  secondNumber_ = value;
}

size_t gorbunova::FindCount::operator()() const
{
  if (countNumbers_ < 3)
  {
    throw std::logic_error("Too short sequence\n");
  }
  else
  {
    return countSum_;
  }
}
