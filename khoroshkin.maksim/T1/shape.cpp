#include "shape.hpp"

void khoroshkin::Shape::scale(double k)
{
  if (k > 0)
  {
    doScale(k);
  }
  else
  {
    throw std::invalid_argument("Error: scale factor must be > 0\n");
  }
}
