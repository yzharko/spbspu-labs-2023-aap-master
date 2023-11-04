k#ifndef FINDEQSEQ_HPP
#define FINDEQSEQ_HPP
#include <cstddef>

namespace reznikova
{
  class MaxEqualSequense
  {
  public:
    MaxEqualSequense();
    void operator()(long long number);
    size_t operator()();
  private:
    size_t count;
    size_t max_count;
    long long previous_number;
  };
}

#endif
