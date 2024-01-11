#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  class CompositeShape {
  public:
    size_t shapes{};
    size_t capacity{};
    Shape **shapeptrs{};

    CompositeShape();

    CompositeShape(const CompositeShape &);

    ~CompositeShape();

    CompositeShape &operator=(CompositeShape another_cs);

    void add(Shape *);

    Shape *pop(long long n = -1);

    void resize(size_t n = 0);

    float getArea();

    rectangle_t *getFrameRect();

    void move(point_t);

    void move(float x, float y);

    void scale(std::ostream &, point_t, float);

    float getDX(point_t fp, point_t sp);

    float getDY(point_t fp, point_t sp);

  };
}

#endif
