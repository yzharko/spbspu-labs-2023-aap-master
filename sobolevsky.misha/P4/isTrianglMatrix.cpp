#include "isTrianglMatrix.hpp"

namespace sobolevsky
{
  void isTrianglMatrix(std::ofstream& out, const int * matrix, size_t rows, size_t cols)
  {
    bool flag = true;
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t k = 0; k < cols; k++)
      {
        if ((matrix[k*cols + i] != 0) && (i > k))
        {
          out << std::boolalpha << false;
          flag = false;
        }
      }
    }
    if (flag)
    {
      out << std::boolalpha << true;
    }
  }
}
