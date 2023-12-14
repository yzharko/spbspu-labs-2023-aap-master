#ifndef GRTLSS_COUNTER_HPP
#define GRTLSS_COUNTER_HPP
#include <cstddef>

namespace shapar
{
  struct GrtlssCounter
  {
  public:
    GrtlssCounter();
    void operator()(size_t thirdNum);
    size_t operator()() const;
  private:
    size_t seqLens = 0;
    size_t secondNum = 0;
    size_t firstNum = 0;
    size_t count = 0;
  };
}

#endif
