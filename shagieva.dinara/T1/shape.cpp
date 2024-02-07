#include "shape.hpp"
#include <stdexcept>

using namespace shagieva;

void Shape::scale(const double scaleFactor)
{
  if (scaleFactor <= 0)
  {
    throw std::invalid_argument("Invalid scale factor entered");
  }
  else
  {
    doScale(scaleFactor);
  }
}
