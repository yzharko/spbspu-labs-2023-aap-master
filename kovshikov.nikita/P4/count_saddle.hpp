#ifndef COUNTSADDLE_HPP
#define COUNTSADDLE_HPP
#include <cstddef>
#include <limits>

namespace kovshikov
{
  struct Saddle
  {
    public:
      Saddle();
      size_t operator()(size_t rows, size_t cols, size_t * matrix);
    private:
      size_t count;
      size_t minrows;
      size_t maxcols;
      size_t coordinateMinRowsj;
  };
}

#endif
