#ifndef T1_READWRITESHAPES_H
#define T1_READWRITESHAPES_H
#include <istream>
#include "shape.hpp"
#include "compositeShape.hpp"
namespace tellez
{
  Shape * createRectangle(std::istream & input);
  Shape * createRing(std::istream & input);
  Shape * createEllipse(std::istream & input);
  scale_t getScale(std::istream & input);
  void printAreaPoints(std::ostream & output, const CompositeShape & compositeShape);
}
#endif
