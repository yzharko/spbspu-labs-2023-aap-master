#ifndef COUNTER_MINIMUMS_HPP
#define COUNTER_MINIMUMS_HPP
#include <cstddef>

namespace popov
{
  struct CountMinSt
  {
    CountMinSt();
    void operator()(int number);
    size_t operator()();
  private:
    size_t count_;
    int min;
  };
}

#endif
