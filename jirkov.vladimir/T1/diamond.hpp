#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace jirkov
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t topPointSec, point_t rightPointSec, point_t centerPointSec);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t destination);
    virtual void move(double moveX, double moveY);
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
