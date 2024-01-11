#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  class Complexquad : public Shape {
  public:
    point_t leftBottom, leftTop, rightTop, rightBottom, cPoint;

    explicit Complexquad();

    ~Complexquad() override = default;

    point_t getCPoint() const;

    float getArea() override;

    rectangle_t getFrameRect() override;

    void move(point_t) override;

    void move(float x, float y) override;

    void scale(float, point_t point) override;

    friend std::istream &operator>>(std::istream &, Complexquad &);

    float getDistance(point_t fp, point_t sp);

    float getTriangleArea(point_t fp, point_t sp, point_t tp);

  };
}

#endif
