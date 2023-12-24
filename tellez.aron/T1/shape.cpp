#include "shape.h"
void tellez::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  unsafeScale(k);
}
