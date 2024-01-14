#ifndef MAXIMUMSUMSTAT_HPP
#define MAXIMUMSUMSTAT_HPP

namespace popov
{
  struct maxSumStat
  {
    void operator()(int * a, int * row, int * col, int * summ, int * maxx);
  };
}

#endif
