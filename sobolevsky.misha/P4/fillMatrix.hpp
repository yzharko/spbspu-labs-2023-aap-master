#ifndef FILLMATRIX_HPP
#define FILLMATRIX_HPP
#include <fstream>

namespace sobolevsky
{
  size_t fillMatrix(std::istream & in, int * matrix, size_t s, size_t counter);
}

#endif
