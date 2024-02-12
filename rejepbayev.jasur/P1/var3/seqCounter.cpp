
#include "seqCounter.hpp"


rejepbayev::jasur::SequenceCounter::SequenceCounter():
  count_(0), lastElement_(0)
{}

void rejepbayev::jasur::SequenceCounter::operator()(int currentElement)
{

  if (lastElement_ != 0 && currentElement != 0 && currentElement > lastElement_)
  {
    ++count_;
  }
  lastElement_ = currentElement;
}

int rejepbayev::jasur::SequenceCounter::operator()() const
{

  return count_;
}
