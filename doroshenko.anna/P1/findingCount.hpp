#ifndef FINDINGCOUNT_HPP
#define FINDINGCOUNT_HPP
#include <cstddef>

namespace doroshenko
{
  struct FindingCount
  {
  public:
    FindingCount();
    void operator()(size_t value);
    size_t operator()() const;
  private:
    size_t countNums_;
    size_t countSum_;
    size_t firstNum_;
    size_t secondNum_;
  };
}

#endif
