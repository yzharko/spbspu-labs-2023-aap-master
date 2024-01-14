#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {
  struct Square : public Shape {
    point_t cPoint;
    double side;

    point_t getCPoint() override;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t) override;

    void move(const double x, const double y) override;

    void scale(double) override;

    friend std::istream &operator>>(std::istream &, Square &);

    static double getDX(point_t fp, point_t sp);

    static double getDY(point_t fp, point_t sp);
  };
}

#endif
