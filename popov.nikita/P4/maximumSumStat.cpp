#include "maximumSumStat.hpp"

void popov::maxSumStat::operator()(int * a, int * row, int * col, int * summ, int * maxx)
{
  for (int j = 1; j <= 2; ++j)
  {
    *summ = 0;
    if (j == 1)
    {
      for (int i = 1; i < *col; ++i)
      {
        *summ = 0;
        *summ = *summ + a[i];
        for (int q = 1; q < i; ++q)
        {
          *summ = *summ + a[i + (q * (*row - 1))];
        }
        if ((*summ > *maxx) and (i * j != 1))
        {
          *maxx = *summ;
        }
        if (i * j == 1)
        {
          if (*maxx < a[j * i])
          {
            *maxx = a[j * i];
          }
        }
      }
    }
    if (j == 2)
    {
      int count = *row;
      for (int w = *row * 2;w <= *row * *col;w += *row)
      {
        *summ = 0;
        *summ = a[w];
        count = count - 1;
        for (int e = 1; e < count; ++e)
        {
          *summ = *summ + a[w + (e * (*row - 1))];
        }
        if ((*summ > *maxx) and (w != *row * *col))
        {
          *maxx = *summ;
        }
        if (w == *row * *col)
        {
          if (*maxx < a[w])
          {
            *maxx = a[w];
          }
        }
      }
    }
  }
}
