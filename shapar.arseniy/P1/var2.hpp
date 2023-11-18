#ifndef SEQUENCE_COUNTER1_HPP
#define SEQUENCE_COUNTER1_HPP
#include <cstddef>

namespace shapar
{
  struct SequenceCounter_
  {
  public:
    SequenceCounter_();

    void operator()(int fourthNum_);

    size_t operator()() const;

  private:
    size_t thirdNum_;
    size_t seqLens_;
    size_t secondNum_;
    size_t firstNum_;
    size_t count_;
  };
}
#endif
