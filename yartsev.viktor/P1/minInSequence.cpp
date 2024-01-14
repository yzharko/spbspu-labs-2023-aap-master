#include "minInSequence.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

yartsev::MinInSequenceCounter::MinInSequenceCounter():
  minElement(std::numeric_limits< int >::max()),
  minCounter(0)
{}

int yartsev::MinInSequenceCounter::operator()()
{
  return minCounter;
}

void yartsev::MinInSequenceCounter::operator()(const int num)
{
  if (num < minElement) {
    minElement = num;
    minCounter = 0;
  }
  if (minElement == num) {
    minCounter++;
  }
}
