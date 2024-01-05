#ifndef COM_SHAPE_HPP
#define COM_SHAPE_HPP
#include "shape.hpp"
#include <vector>
struct CompositeShape
{
  CompositeShape();
  CompositeShape(std::vector<Shape*>);
  CompositeShape(const CompositeShape&);
  CompositeShape(CompositeShape&&);
  void operator+=(Shape*);
  void operator-=(Shape*);

  std::vector<Shape*> shapeptrs;
  size_t shapes;
  size_t capacity;
  
  double getArea();
  std::vector<rectangle_t> getFrameRect();
  void move(std::vector<point_t>);
  void move(double x, double y);
  void scale(point_t, double);
};
#endif
