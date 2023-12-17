#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace zheleznyakov
{
  class Rectangle : public zheleznyakov::Shape
  {
  public:
    Rectangle(const point_t leftTopPoint, const point_t RightBottomPoint);
    virtual double getArea() override;
    virtual rectangle_t getFrameRect() override;
    virtual void move(double x, double y) override;
    virtual void move(zheleznyakov::point_t point) override;
    virtual void scale(double k) override;
  };
};
#endif