#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace jirkov
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t topPoint, point_t rightPoint, point_t centerPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & center);
    virtual void move(const double moveX, const double moveY);
    virtual void scale(double k);
  private:
    point_t topPoint_;
    point_t rightPoint_;
    point_t centerPoint_;
    double firstSide_;
    double secondSide_;
  };
}

#endif
