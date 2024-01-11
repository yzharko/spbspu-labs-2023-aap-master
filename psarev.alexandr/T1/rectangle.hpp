#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace psarev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t firPoint, point_t secPoint);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(point_t newCenter) override;
    virtual void move(double xCh, double yCh) override;
    virtual void scale(double coef) override;
  private:
    point_t llCorner;
    point_t urCorner;
    point_t center;
  };
}

#endif
