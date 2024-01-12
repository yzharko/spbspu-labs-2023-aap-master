#ifndef LESSMORE_HPP
#define LESSMORE_HPP
#include <cstddef>

namespace hohlova
{
  struct LessMore
  {
  public:
    LessMore();
    void operator()(int prev, int curr, int next);
    size_t operator()() const;
  private:
    size_t countres_;
  };
}
#endif
