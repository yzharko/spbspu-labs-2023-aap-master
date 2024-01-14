#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "../shape.hpp"
#include "../shapesCommon.hpp"

namespace likhachev
{
  class Rectangle: public Shape {
    public:
      Rectangle(likhachev::point_t lowerLeft, likhachev::point_t upperRight);
      Rectangle(double lowerLeftX, double lowerLeftY, double upperRightX, double upperRightY);
      virtual double getArea() const;
      virtual likhachev::rectangle_t getFrameRect() const;
      virtual void move(likhachev::point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual likhachev::point_t getPos() const;
      double getWidth() const;
      double getHeight() const;
    private:
      likhachev::point_t lowerLeft_;
      likhachev::point_t upperRight_;
  };
}
#endif
