#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP
#include <cstddef>

namespace bronson
{
  struct SequenceCounter
  {
  public:
    SequenceCounter();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t seqLength_;
  };
}
#endif
