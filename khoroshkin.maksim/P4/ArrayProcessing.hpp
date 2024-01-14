#ifndef ARRAYPROCESSING_HPP
#define ARRAYPROCESSING_HPP
#include <iostream>

namespace khoroshkin
{
  bool isNumber(char * str);
  void fillingRowsAndCols(std::istream & in, int & Rows, int & Cols);
  void fillingOutputFile(std::ostream & out, int * matrix, int Rows, int Cols);
  int inputArray(std::istream & in, int * matrix, int sizeMatrix);
}

#endif
