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

    float getArea() override;

    rectangle_t getFrameRect() override;

    void move(point_t) override;

    void move(float x, float y) override;

    void scale(float, point_t center = point_t(0, 0)) override;

    friend std::istream &operator>>(std::istream &, Square &);
  };
}

#endif
