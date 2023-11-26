#ifndef SEQUENCE_COUNTER1_HPP
#define SEQUENCE_COUNTER1_HPP
#include <cstddef>

namespace shapar_
{
  struct SequenceCounter_
  {
  public:
    SequenceCounter_();
    void operator()(size_t fourthNum_);
    size_t operator()() const;
  private:
    size_t thirdNum_ = 0;
    size_t seqLens_ = 0;
    size_t secondNum_ = 0;
    size_t firstNum_ = 0;
    size_t count_ = 0;
  };
}

#endif
