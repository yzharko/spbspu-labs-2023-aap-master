#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "getMinSum.hpp"
#include "readMatrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid number of arguments." << '\n';
    return 1;
  }
  std::ifstream file(argv[2]);
  size_t rows, columns;
  file >> rows >> columns;
  if (!file)
  {
    std::cerr << "Error reading matrix dimensions.\n";
    return 1;
  }
  size_t * matrix = nullptr;
  try
  {
    char* end = nullptr;
    size_t num = std::strtoll(argv[1], std::addressof(end), 10);
    if (*end != '\0')
    {
      std::cerr << "Invalid input format for the first argument.\n";
    }
    if (num == 1 || num == 2)
    {
      size_t size_of_matrix = rows * columns;
      std::vector< size_t > static_matrix(10000);
      matrix = (num == 1) ? static_matrix.data() : new size_t[size_of_matrix];
      size_t result = readMatrix(file, matrix, size_of_matrix, size_of_matrix);
      if (!(result == size_of_matrix))
      {
        std::cerr << "Cannot read an array. Read " << result << " elements.\n";
        if (num == 2)
        {
          delete[] matrix;
        }
        return 2;
      }
      std::ofstream out(argv[3]);
      size_t min_sum = getMinSum(matrix, rows, columns);
      out << min_sum << "\n";
      if (num == 2)
      {
        delete[] matrix;
      }
    }
    else
    {
      std::cerr << "Error: No such parameter\n";
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Error:\n" << e.what() << '\n';
    delete[] matrix;
    return 1;
  }
  return 0;
}
