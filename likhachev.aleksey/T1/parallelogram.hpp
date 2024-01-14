#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace likhachev
{
  class Parallelogram: public Shape {
    public:
      Parallelogram(point_t pointB, point_t pointA, point_t pointD);
      Parallelogram(double pointBX, double pointBY, double pointAX, double pointAY, double pointDX, double pointDY);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t& offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual point_t getPos() const;
      double getWidth() const;
      double getSubWidth() const;
      double getHeight() const;
    private:
      point_t pointA_;
      point_t pointB_;
      point_t pointD_;
  };
}
#endif
