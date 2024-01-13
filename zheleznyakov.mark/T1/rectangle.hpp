#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace zheleznyakov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftBottomPoint, point_t rightTopPoint);
    virtual double getArea() override;
    virtual rectangle_t getFrameRect() override;
    virtual void move(double x, double y) override;
    virtual void move(zheleznyakov::point_t point) override;
    virtual void scale(double k) override;
  private:
    zheleznyakov::rectangle_t rectangle;
  };
  bool checkIsRectangleCoords(double x1, double y1, double x2, double y2);
};
#endif
