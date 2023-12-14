#include <cstring>
#include "ArrayProcessing.hpp"
#include "algorithm.hpp"

bool khoroshkin::isNumber(char * str)
{
  for (size_t i = 0; i < std::strlen(str); i++)
  {
    if (!(std::isdigit(str[i])))
    {
      return false;
    }
  }
  return true;
}

void khoroshkin::fillingRowsAndCols(std::istream & in, int & Rows, int & Cols)
{
  if (in.fail())
  {
    throw std::logic_error("Cannot open an output.\n");
  }
  if (!(in >> Rows >> Cols))
  {
    throw std::logic_error("Cannot read an input.\n");
  }
}

int khoroshkin::inputArray(std::istream & in, int * matrix, int sizeMatrix)
{
  for (int i = 0; i < sizeMatrix; i++)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return sizeMatrix;
}

void khoroshkin::fillingOutputFile(std::ostream & out, int * matrix, int Rows, int Cols)
{
  if (out.fail())
  {
    throw std::logic_error("Cannot open an output.\n");
  }
  out << khoroshkin::minSumOfParallelArray(matrix, Rows, Cols);
}
