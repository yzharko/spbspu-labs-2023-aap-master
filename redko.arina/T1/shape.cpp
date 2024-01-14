#include "shape.hpp"
#include <stdexcept>

void redko::Shape::scale(double coefficient)
{
  if (coefficient > 0)
  {
    doScale(coefficient);
  }
  else
  {
    throw std::logic_error("wrong scale coefficient\n");
  }
}
