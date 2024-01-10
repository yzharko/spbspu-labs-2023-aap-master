#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  class Complexquad : public Shape {
  public:
    PointT point1, point2, point3, point4, cPoint;

    explicit Complexquad();

    ~Complexquad() override = default;

    PointT getCPoint() const;

    long long getArea() override;

    RectangleT getFrameRect() override;

    void move(PointT) override;

    void move(float x, float y) override;

    void scale(float) override;

    friend std::istream &operator>>(std::istream &, Complexquad &);

    float getDX(PointT fp, PointT sp);

    float getDY(PointT fp, PointT sp);

    float getDistance(PointT fp, PointT sp);

    float getTriangleArea(PointT fp, PointT sp, PointT tp);

  };
}

#endif
