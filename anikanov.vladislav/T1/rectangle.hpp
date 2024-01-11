#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {
  class Rectangle : public Shape {
  public:
    float width;
    float height;
    point_t cPoint;
    explicit Rectangle();

    ~Rectangle() override = default;

    void setWidth(float);

    float getWidth() const;

    void setHeight(float);

    float getHeight() const;

    point_t getCPoint() const;

    float getArea() override;

    rectangle_t getFrameRect() override;

    void move(point_t) override;

    void move(float x, float y) override;

    void scale(float, point_t center = point_t(0, 0)) override;

    friend std::istream &operator>>(std::istream &, Rectangle &);
  };
}
#endif
