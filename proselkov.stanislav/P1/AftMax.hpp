#ifndef AFTMAX_HPP
#define AFTMAX_HPP
#include <cstddef>

namespace proselkov
{
  struct AftMax
  {
  public:
    AftMax();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t aftMax_;
    int max_number;
  };
}
#endif
