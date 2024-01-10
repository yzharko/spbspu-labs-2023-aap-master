#ifndef INPUTOUTPUT_HPP
#define INPUTOUTPUT_HPP
#include <iostream>

namespace MatrixStuff
{
  void writeResult(std::ostream &output, int result, bool UpperTriangularMatrix);
  int readMatrix(std::istream &input, int *matrixPointer, int n, int m);
}

#endif
