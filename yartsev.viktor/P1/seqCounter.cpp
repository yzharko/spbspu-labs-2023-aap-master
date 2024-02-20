#include "seqCounter.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

yartsev::SequenceCounter::SequenceCounter():
  maxSequence(0),
  currentSequence(0),
  minElement(std::numeric_limits< int >::max()),
  minCounter(0)
{}

void yartsev::SequenceCounter::operator()()
{
  std::cout << maxSequence << "\n" << minCounter << "\n";
}

void yartsev::SequenceCounter::updateMinCounter(int num)
{
  if (num < minElement) {
    minElement = num;
    minCounter = 0;
  }
  if (minElement == num) {
    minCounter++;
  }
}

void yartsev::SequenceCounter::updateMaxSequence(int num)
{
  const int maxSize = std::numeric_limits< int >::max();
  if (num % 2 == 0) {
    if (currentSequence == maxSize) {
      throw std::overflow_error("Sequence is too long");
    } else {
      currentSequence++;
    }
  } else {
    currentSequence = 0;
  }
  maxSequence = std::max(maxSequence, currentSequence);
}
