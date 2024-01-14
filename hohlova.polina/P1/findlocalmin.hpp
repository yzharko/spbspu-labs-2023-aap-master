#ifndef FINDLOCALMIN_HPP
#define FINDLOCALMIN_HPP
#include <cstddef>

namespace hohlovaa
{
  struct FindLocalMin
  {
  public:
    FindLocalMin();
    void operator()(int prev, int curr, int next);
    size_t operator()() const;
  private:
    size_t countmins_;
  };
}
#endif
