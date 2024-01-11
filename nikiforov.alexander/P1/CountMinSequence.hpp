#ifndef COUNTMINSEQUENCE_HPP
#define COUNTMINSEQUENCE_HPP
#include <limits>
#include <cstddef>
#include <fstream>

namespace nikiforov {
  class Sequence
  {
  public:
    Sequence();
    void operator()(int& value);
    size_t operator()();
  private:
    size_t count;
    bool direction;
    size_t max_count;
    int beforvalue;
  };
}
#endif
