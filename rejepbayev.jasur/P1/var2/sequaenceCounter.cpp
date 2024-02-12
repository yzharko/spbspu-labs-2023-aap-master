#include "sequaenceCounter.hpp"
#include <string>

void number::SequenceCounter::updateAndCountSequence()
{
  sequenceUpdates++;
  if (sequenceUpdates > 2 && secondNum < firstNum && secondNum > thirdNum)
  {
    sequenceUpdateser++;
  }
}

void number::SequenceCounter::operator()(int& newNumber)
{
  firstNum = secondNum;
  secondNum = thirdNum;
  thirdNum = newNumber;
}

int number::SequenceCounter::getSequenceCount()
{
  if (sequenceUpdates < 3)
  {
    throw std::string("not enough number\\n");
  }
  return sequenceUpdateser;
}
