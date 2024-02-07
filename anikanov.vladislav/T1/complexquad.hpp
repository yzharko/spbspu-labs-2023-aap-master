#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {

  struct Complexquad : public Shape {
    point_t leftBottom, leftTop, rightTop, rightBottom, cPoint;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t) override;

    void move(const double x, const double y) override;

    void scale(const double) override;

    point_t getCPoint() override;

    friend std::istream &operator>>(std::istream &, Complexquad &);

    double getDistance(point_t fp, point_t sp);

    double getTriangleArea(point_t fp, point_t sp, point_t tp) const;

    double getDX(point_t fp, point_t sp);

    double getDY(point_t fp, point_t sp);

  };
}

#endif
