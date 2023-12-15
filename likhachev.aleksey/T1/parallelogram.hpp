#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace likhachev
{
  class Parallelogram: public Shape {
    public:
      Parallelogram();
      Parallelogram(Point_t pointA, Point_t pointB, Point_t pointD);
      Parallelogram(double pointAX, double pointAY, double pointBX, double pointBY, double pointDX, double pointDY);
      virtual double getArea() const;
      virtual likhachev::Rectangle_t getFrameRect() const;
      virtual void move(Point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      double getWidth() const;
      double getSubWidth() const;
      double getHeight() const;
    private:
      Point_t pointA_;
      Point_t pointB_;
      Point_t pointD_;
  };
}
#endif
