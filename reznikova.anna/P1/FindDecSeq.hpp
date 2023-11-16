#ifndef FINDDECSEQ_HPP
#define FINDDECSEQ_HPP
#include <cstddef>

namespace reznikova
{
  class MaxDecreasingSequence
  {
  public:
    MaxDecreasingSequence();
    void operator()(long long number);
    size_t operator()();
  private:
    size_t count;
    size_t max_count;
    long long previous_number;
  };
}

#endif
