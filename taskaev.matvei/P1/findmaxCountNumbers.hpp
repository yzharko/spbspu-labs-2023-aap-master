#ifndef FINDMAXCOUNTNUMBERS_HPP
#define FINDMAXCOUNTNUMBERS_HPP
#include <cstddef>

namespace taskaev
{
  class findmaxCountNumbers
  {
  public:
    findmaxCountNumbers();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t maxCount_;
    size_t count_;
    int previousNum_;
    size_t countNum_;
  };
}
#endif
