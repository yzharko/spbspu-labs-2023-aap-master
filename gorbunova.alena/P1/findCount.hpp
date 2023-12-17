#ifndef FINDCOUNT_HPP
#define FINDCOUNT_HPP
#include <cstddef>

namespace gorbunova
{
  struct FindCount
  {
  public:
    FindCount();
    void operator()(size_t value);
    size_t operator()() const;
  private:
    size_t countNumbers_;
    size_t countSum_;
    size_t firstNumber_;
    size_t secondNumber_;
  };
}

#endif
