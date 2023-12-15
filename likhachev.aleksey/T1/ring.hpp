#ifndef RING_HPP
#define RING_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace likhachev
{
  class Ring: public Shape {
    public:
      Ring();
      Ring(Point_t pos, double outerRad, double innerRad);
      Ring(double posX, double posY, double outerRad, double innerRad);
      virtual double getArea() const;
      virtual likhachev::Rectangle_t getFrameRect() const;
      virtual void move(Point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      double getOuterRad() const;
      double getInnerRad() const;
    private:
      double outerRad_;
      double innerRad_;
      Point_t pos_;
  };
}
#endif
