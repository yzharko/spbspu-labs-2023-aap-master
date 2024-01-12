#include <iostream>
#include <limits>
#include <stdexcept>
#include "Counter.hpp"

mihalchenko::CounterAfterMax::CounterAfterMax()
{
  countNumAfterMax_ = 0;
  fMinus_ = 0;
  fPlus_ = 0;
  fMaxNum_ = 0;
}

void mihalchenko::CounterAfterMax::operator()(int number, int)
{
  const unsigned int maxSize = std::numeric_limits< unsigned int >::max();
  if (countNumAfterMax_ == maxSize)
  {
    throw std::logic_error("Sequence is too long");
  }
  (number > fMaxNum_) ? (fMaxNum_ = number, countNumAfterMax_ = 0) : (countNumAfterMax_ += 1);
  (number < 0) ? (fMinus_+= 1) : (fPlus_ += 1);
}

unsigned int mihalchenko::CounterAfterMax::operator()(int seqCounter) const
{
  if (((fMinus_ == 0) || (fPlus_ == 0)) && (seqCounter > 1))
  {
    std::cerr << "The sequence includes numbers of the same sign\n";
    return 1;
  }
  if (seqCounter > 1)
  {
    return countNumAfterMax_;
  }
  else
  {
    std::cerr << "The sequence is empty\n";
    return 2;
  }
}
