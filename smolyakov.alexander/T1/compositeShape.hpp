#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace smolyakov
{
  struct CompositeShape
  {
  public:
    std::size_t shapes;
    std::size_t capacity;
    Shape** shapeptrs;
    CompositeShape(size_t capacity);
    CompositeShape(const CompositeShape& source);
    CompositeShape(CompositeShape&& source);
    ~CompositeShape();
    void addShape(Shape& shape);
    void removeShape(Shape& shape);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void moveBy(point_t shift);
    void scale(point_t pivot, double factor);
  private:
    void doForAllShapes(void (Shape::* Action)());
  };
}

#endif
