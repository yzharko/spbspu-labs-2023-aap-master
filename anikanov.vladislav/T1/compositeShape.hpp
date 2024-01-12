#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  struct CompositeShape {
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

    double getArea();

    rectangle_t *getFrameRect();

    void move(point_t);

    void move(const double x, const double y);

    void scale(std::ostream &, point_t, double);

    double getDX(point_t fp, point_t sp);

    double getDY(point_t fp, point_t sp);
  };
}

#endif
