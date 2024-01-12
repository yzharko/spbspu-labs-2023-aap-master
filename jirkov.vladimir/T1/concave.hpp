#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace jirkov
{
  class Concave : public Shape
  {
  public:
    Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourtPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & center);
    virtual void move(const double moveX, const double moveY);
    virtual void scale(double k);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
    point_t fourthPoint_;
  };
}

#endif
