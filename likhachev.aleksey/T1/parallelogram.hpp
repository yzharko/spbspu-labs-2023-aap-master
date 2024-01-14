#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace likhachev
{
  class Parallelogram: public Shape {
    public:
      Parallelogram(likhachev::point_t pointB, likhachev::point_t pointA, likhachev::point_t pointD);
      Parallelogram(double pointBX, double pointBY, double pointAX, double pointAY, double pointDX, double pointDY);
      virtual double getArea() const;
      virtual likhachev::rectangle_t getFrameRect() const;
      virtual void move(likhachev::point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual likhachev::point_t getPos() const;
      double getWidth() const;
      double getSubWidth() const;
      double getHeight() const;
    private:
      likhachev::point_t pointA_;
      likhachev::point_t pointB_;
      likhachev::point_t pointD_;
  };
}
#endif
