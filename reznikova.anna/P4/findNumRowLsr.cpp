#include "findNumRowLsr.hpp"

size_t reznikova::findNumRowLsr(const int * matrix, size_t rows, size_t cols)
{
  size_t num_row_lsr = 0;
  int max_count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    int previous_number = 0;
    int count = 0;
    for (size_t j = 0; j < cols; j++)
    {
      int number = matrix[i*cols + j];
      if (number != previous_number)
      {
        previous_number = number;
        count = 1;
      }
      else
      {
        count++;
      }
      if (count > max_count)
      {
        max_count = count;
        num_row_lsr = i + 1;
      }
    }
  }

  return (num_row_lsr);
}
