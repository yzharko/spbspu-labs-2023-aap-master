#include "class.hpp"

namespace sobolevsky
{
  Array::Array(size_t sizeArr)
  {
    size = sizeArr;
    str = new char[size];
  }
}
