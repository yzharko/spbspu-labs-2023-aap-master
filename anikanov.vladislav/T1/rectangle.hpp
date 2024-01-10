#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace anikanov {
  class Rectangle : public Shape {
  public:
    explicit Rectangle();

    ~Rectangle() override = default;

    void setWidth(float);

    float getWidth() const;

    void setHeight(float);

    float getHeight() const;

    PointT getCPoint() const;

    long long getArea() override;

    RectangleT getFrameRect() override;

    void move(PointT) override;

    void move(float x, float y) override;

    void scale(float) override;

    friend std::istream &operator>>(std::istream &, Rectangle &);

  private:
    float width;
    float height;
    PointT cPoint;
  };
}
#endif
