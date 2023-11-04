#ifndef FINDEQSEQ_HPP
#define FINDEQSEQ_HPP
#include <cstddef>

namespace reznikova
{
  class FindMaxEqualSequense
  {
  public:
    FindMaxEqualSequense();
    void operator()(long long number);
    size_t operator()();
  private:
    size_t count;
    size_t max_count;
    long long previous_number;
  };
}

#endif
