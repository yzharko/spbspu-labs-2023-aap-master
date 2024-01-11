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

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t) override;

    void move(const float x, const float y) override;

    void scale(const float, const point_t center = point_t(0, 0)) override;

    friend std::istream &operator>>(std::istream &, Rectangle &);
  };
}
#endif
