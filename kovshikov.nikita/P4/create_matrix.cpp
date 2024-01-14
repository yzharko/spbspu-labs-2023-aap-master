#include "create_matrix.hpp"

void createMatrix (size_t * matrix, char * fail)
{
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(fail);
  input >> rows >> cols;
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      input >> matrix[i * cols + j];
    };
  };
};
