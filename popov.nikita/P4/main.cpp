#include <iostream>
#include <fstream>
#include "maximumSumStat.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  char * endOfParcing = nullptr;
  int num = std::strtoll(argv[1], &endOfParcing, 10);
  if (*endOfParcing != '\0')
  {
    std::cerr << "First argument not int";
    return 2;
  }
  if (num != 1 and num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  int rows = 1;
  int cols = 1;
  int max = 0;
  int sum = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (input.peek() == EOF and (rows != 0 and cols != 0))
  {
    std::cerr << "not enough information\n";
    return 2;
  }
  if ((rows == 0) and (cols == 0))
  {
    std::ofstream out(argv[3]);
    out << max;
    return 0;
  }
  if (num == 1)
  {
    using namespace popov;
    maxSumStat maxsSumStat;
    int a[10000] = {0};
    int value = 0;
    for (int i = 1; i <= rows * cols; ++i)
    {
      if (input.peek() == EOF)
      {
        std::cerr << "not enough data\n";
        return 2;
      }
      input >> value;
      a[i] = value;
    }
    maxsSumStat(a, &rows, &cols, &sum, &max);
    std::ofstream out(argv[3]);
    out << max;
  }
  if (num == 2)
  {
    int * dynarr = new int[(rows * cols) + 1];
    for (int i = 1; i <= rows * cols; ++i)
    {
      int value = 0;
      if (input.peek() == EOF)
      {
        std::cerr << "not enough data\n";
        delete [] dynarr;
        return 2;
      }
      input >> value;
      dynarr[i] = value;
    }
    using namespace popov;
    maxSumStat maxsSumStat;
    maxsSumStat(dynarr, &rows, &cols, &sum, &max);
    std::ofstream out(argv[3]);
    out << max;
    delete [] dynarr;
  }
  return 0;
}
