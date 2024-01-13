#include "shape.hpp"
#include <stdexcept>

using namespace tellez;

void Shape::scaleWithVerify(double ds)
{
  if (ds <= 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  scaleWithoutVerify(ds);
}
