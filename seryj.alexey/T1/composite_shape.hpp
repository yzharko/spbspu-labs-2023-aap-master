#ifndef COM_SHAPE_HPP
#define COM_SHAPE_HPP
#include <vector>
#include "shape.hpp"
namespace seryj {
  struct CompositeShape
  {
    CompositeShape();
    CompositeShape(std::vector<Shape*>);
    CompositeShape(const CompositeShape&);
    ~CompositeShape();
    void operator+=(Shape*);
    void operator-=(Shape*);
    double getArea()const;
    std::vector<rectangle_t> getFrameRect()const;
    void move(std::vector<point_t>);
    void move(double x, double y);
    void scale(point_t, double);
    size_t capacity;
    std::vector<Shape*> shape_vector;
    size_t shapes_amount;
  };
}
#endif
