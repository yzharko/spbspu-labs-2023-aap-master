#ifndef	SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP
#include <cstddef>

namespace shapar
{
  struct SequenceCounter
  {
  public:
    SequenceCounter();

    void operator()(int thirdNum);

    size_t operator()() const;

  private:
    size_t seqLens;
    int secondNum;
    int firstNum;
    int count = 0;
  };
}
#endif
