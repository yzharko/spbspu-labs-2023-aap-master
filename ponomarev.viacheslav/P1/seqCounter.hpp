#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP
#include <cstddef>

namespace ponomarev
{
  struct SequenceCounter
  {
  public:
    SequenceCounter();
    void operator()(size_t number);
    size_t operator()() const;
  private:
    size_t seqLength_;
    size_t firstNum_;
    size_t secondNum_;
    size_t countLocmax_;
  };
}
#endif
