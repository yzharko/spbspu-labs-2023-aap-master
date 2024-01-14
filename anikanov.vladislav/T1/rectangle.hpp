#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {
  struct Rectangle : public Shape {
    point_t cPoint;
    double width;
    double height;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t) override;

    void move(const double, const double) override;

    void scale(const double) override;

    point_t getCPoint() override;

    static double getDX(point_t fp, point_t sp);

    static double getDY(point_t fp, point_t sp);

    friend std::istream &operator>>(std::istream &, Rectangle &);
  };
}
#endif
