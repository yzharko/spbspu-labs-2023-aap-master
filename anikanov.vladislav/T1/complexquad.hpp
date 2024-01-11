#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  class Complexquad : public Shape {
  public:
    PointT leftBottom, leftTop, rightTop, rightBottom, cPoint;

    explicit Complexquad();

    ~Complexquad() override = default;

    PointT getCPoint() const;

    float getArea() override;

    RectangleT getFrameRect() override;

    void move(PointT) override;

    void move(float x, float y) override;

    void scale(float, PointT point) override;

    friend std::istream &operator>>(std::istream &, Complexquad &);

    float getDX(PointT fp, PointT sp);

    float getDY(PointT fp, PointT sp);

    float getDistance(PointT fp, PointT sp);

    float getTriangleArea(PointT fp, PointT sp, PointT tp);

  };
}

#endif
