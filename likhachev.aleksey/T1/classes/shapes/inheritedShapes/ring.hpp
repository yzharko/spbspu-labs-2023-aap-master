#ifndef RING_HPP
#define RING_HPP
#include "../shape.hpp"
#include "../shapesCommon.hpp"

namespace likhachev
{
  class Ring: public Shape {
    public:
      Ring(Point_t pos, double outerRad, double innerRad);
      Ring(double posX, double posY, double outerRad, double innerRad);
      virtual double getArea() const;
      virtual likhachev::Rectangle_t getFrameRect() const;
      virtual void move(Point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual likhachev::Point_t getPos() const;
      double getOuterRad() const;
      double getInnerRad() const;
    private:
      double outerRad_;
      double innerRad_;
      Point_t pos_;
  };
}
#endif
