#include <iostream>
#include <fstream>
#include "inputArray.hpp"
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Something wrong, I can feel it.\n";
    return 1;
  }

  try
  {
    static int num = std::stoll(argv[1]);
    size_t rows = 0, cols = 0;

    std::ifstream input(argv[2]);
    input >> rows >> cols;

    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }

    if (num == 1)
    {
      int matrix[10000] = {0};
      size_t result = readArray::inputArray(input, matrix, rows * cols, rows * cols);
      if (result != cols*rows)
      {
        std::cerr << "sorry";
        return 2;
      }
      int res = susidko::countUniqueRows(matrix, rows, cols);
      int res1 = susidko::getColNumber(matrix, rows, cols);
      std::ofstream output(argv[3]);
      output << res << "\n" << res1;
    }
    else if (num == 2)
    {
      int * matrix = new int[rows * cols];
      size_t result = readArray::inputArray(input, matrix, rows * cols, rows * cols);
      if (result != cols*rows)
      {
        std::cerr << "sorry";
        delete[] matrix;
        return 2;
      }
      int res = susidko::countUniqueRows(matrix, rows, cols);
      int res1 = susidko::getColNumber(matrix, rows, cols);
      std::ofstream output(argv[3]);
      output << res << "\n" << res1;
      delete[] matrix;
    }
    else
    {
      std::cout << "Firts parametr is wrong";
      return 2;
    }
    return 0;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }
}
