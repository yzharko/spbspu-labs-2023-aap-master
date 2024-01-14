#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace likhachev
{
  class Rectangle: public Shape {
    public:
      Rectangle(point_t lowerLeft, point_t upperRight);
      Rectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t& offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual point_t getPos() const;
      double getWidth() const;
      double getHeight() const;
    private:
      point_t lowerLeft_;
      point_t upperRight_;
  };
}
#endif
