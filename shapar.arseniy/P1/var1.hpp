#ifndef SEQUENCECOUNTER_HPP
#define SEQUENCECOUNTER_HPP
#include <cstddef>

namespace shapar
{
  struct SequenceCounter
  {
  public:
    SequenceCounter();
    void operator()(size_t thirdNum);
    size_t operator()() const;
  private:
    size_t seqLens;
    size_t secondNum;
    size_t firstNum;
    size_t count;
  };
}

#endif
