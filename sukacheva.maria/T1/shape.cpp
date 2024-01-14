#include "shape.hpp"
#include <iostream>

void sukacheva::Shape::scale(double k)
{
  if (k <= 0) {
    throw std::logic_error("Incorrect scaling factor\n");
  }
  else {
    scaling(k);
  }
}
