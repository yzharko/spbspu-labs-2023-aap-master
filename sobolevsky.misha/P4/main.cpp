#include <iostream>
#include <fstream>
#include <cstring>
#include "fillMatrix.hpp"
#include "isTrianglMatrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "you did not pass 4 arguments\n";
    return 1;
  }

  char * endOfParsing = nullptr;
  int number = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  if (*endOfParsing != '\0')
  {
    std::cerr << "the first argument should be int\n";
    return 1;
  }

  if (!(number == 1 || number == 2))
  {
    std::cerr << "first argument should be either 1 or 2\n";
    return 1;
  }
  else
  {
    std::ifstream input(argv[2]);
    size_t rows, cols;
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "input file cannot be opened\n";
      return 2;
    }

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "output file cannot be opened\n";
      return 2;
    }

    int statArray[10000] = {};
    int * matrix = (number == 1) ? statArray : new int[cols * rows];
    size_t counter = 0;
    counter = sobolevsky::fillMatrix(input, matrix, (cols * rows), counter);
    if (counter != (cols*rows))
    {
      std::cerr << "matrix size and number of numbers are different\n";
      if (number == 2)
      {
        delete[] matrix;
      }
      return 2;
    }
    sobolevsky::isTrianglMatrix(output, matrix, rows, cols);
    if (number == 2)
    {
      delete[] matrix;
    }
    return 0;
  }
}
