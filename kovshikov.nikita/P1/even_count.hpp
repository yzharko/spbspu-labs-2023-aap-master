#ifndef EVEN_COUNT_HPP
#define EVEN_COUNT_HPP
#include <cstddef>
#include <stdexcept>
#include <limits>

namespace kovshikov
{
  struct EvenCount
  {
    public:
      EvenCount();
      void operator()(size_t num);
      size_t operator()();
    private:
      size_t count_;
      size_t max_count_;
  };
}

#endif
