#include "square.hpp"
#include <cstring>
#include "shape.hpp"

mihalchenko::Square::Square()
{
}

mihalchenko::Square::~Square()
{
}

float mihalchenko::Square::getArea(float x, float y, float width)
{
  return width * width;
}
