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

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t) override;

    void move(const float x, const float y) override;

    void scale(const double) override;

    void myscale(const double, const point_t point) override;

    friend std::istream &operator>>(std::istream &, Complexquad &);

    float getDistance(point_t fp, point_t sp);

    float getTriangleArea(point_t fp, point_t sp, point_t tp) const;

  };
}

#endif
