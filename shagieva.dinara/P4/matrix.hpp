#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>

namespace shagieva
{
  struct Matrix
  {
    int numberOfRows;
    int numberOfColumns;
    void read(std::ifstream & input);
    int findMaxColumn();
    int * values;
  };
}
#endif
