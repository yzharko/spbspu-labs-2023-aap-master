#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {
  class Square : public Shape {
  public:
    point_t cPoint;
    float side;

    explicit Square();

    ~Square() override = default;

    void setSide(float);

    float getSide() const;

    point_t getCPoint() const;

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t) override;

    void move(const float x, const float y) override;

    void scale(double) override;

    void myscale(const double, const point_t center = point_t(0, 0)) override;

    friend std::istream &operator>>(std::istream &, Square &);
  };
}

#endif
