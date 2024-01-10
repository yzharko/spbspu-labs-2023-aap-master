#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  class CompositeShape {
  public:
    CompositeShape();

    CompositeShape(const CompositeShape &);

    ~CompositeShape();

    CompositeShape &operator=(CompositeShape another_cs);

    void add(Shape *);

    Shape *pop(long long n = -1);

    void resize(size_t n = 0);

    float getArea();

    RectangleT *getFrameRect();

    void move(PointT);

    void move(float x, float y);

    void scale(std::ostream &, PointT, float);

  protected:
    size_t shapes{};
    size_t capacity{};
    Shape **shapeptrs{};

    float getDX(PointT fp, PointT sp);

    float getDY(PointT fp, PointT sp);
  };
}

#endif
