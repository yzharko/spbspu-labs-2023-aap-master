#ifndef RING_HPP
#define RING_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace likhachev
{
  class Ring: public Shape {
    public:
      Ring(likhachev::point_t pos, double outerRad, double innerRad);
      Ring(double posX, double posY, double outerRad, double innerRad);
      virtual double getArea() const;
      virtual likhachev::rectangle_t getFrameRect() const;
      virtual void move(likhachev::point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual likhachev::point_t getPos() const;
      double getOuterRad() const;
      double getInnerRad() const;
    private:
      double outerRad_;
      double innerRad_;
      likhachev::point_t pos_;
  };
}
#endif
