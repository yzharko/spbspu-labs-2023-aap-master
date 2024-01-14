#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "../shape.hpp"
#include "../shapesCommon.hpp"

namespace likhachev
{
  class Rectangle: public Shape {
    public:
      Rectangle(Point_t lowerLeft, Point_t upperRight);
      Rectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY);
      virtual double getArea() const;
      virtual likhachev::Rectangle_t getFrameRect() const;
      virtual void move(Point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual likhachev::Point_t getPos() const;
      double getWidth() const;
      double getHeight() const;
    private:
      Point_t lowerLeft_;
      Point_t upperRight_;
  };
}
#endif
