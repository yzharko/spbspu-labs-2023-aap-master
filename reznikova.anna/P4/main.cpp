#include <iostream>
#include <fstream>
#include "findNumRowLsr.hpp"
#include "inputArray.hpp"

int main(int argc, char ** argv)
{
  using namespace reznikova;
  if (argc != 4)
  {
    std::cerr << "Wrong number of arguments.\n";
    return 1;
  }
  char * end = nullptr;
  long long num = 0;
  num = std::strtoll(argv[1], std::addressof(end), 10);
  if (*end != '\0')
  {
    std::cerr << "Can't parse a value.\n";
    return 1;
  }
  else if (num < 1 || num > 2)
  {
    std::cerr << "Argument num must be either 1 or 2. \n";
    return 1;
  }
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Can't read an input.\n";
      return 2;
    }
    size_t capacity = rows * cols;
    size_t result = 0;
    int smatrix[10000];
    int * matrix = (num == 1) ? smatrix : new int[capacity];
    size_t readed = 0;
    readed = reznikova::inputArray(input, matrix, capacity, capacity);
    if (readed != (capacity))
    {
     std::cerr << "Wrong input. Readed only " << readed << " out of " << (capacity) << "\n";
     if (num == 2)
     {
       delete [] matrix;
     }
     return 2;
    }
    result = reznikova::findNumRowLsr(matrix, rows, cols);
    if (num == 2)
    {
      delete [] matrix;
    }
    std::ofstream output(argv[3]);
    output << result << "\n";
  }
  return 0;
}
