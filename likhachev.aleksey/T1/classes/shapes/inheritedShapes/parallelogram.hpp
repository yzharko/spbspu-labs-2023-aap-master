#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "../shape.hpp"
#include "../shapesCommon.hpp"

namespace likhachev
{
  class Parallelogram: public Shape {
    public:
      Parallelogram(likhachev::Point_t pointA, likhachev::Point_t pointB, likhachev::Point_t pointD);
      Parallelogram(double pointAX, double pointAY, double pointBX, double pointBY, double pointDX, double pointDY);
      virtual double getArea() const;
      virtual likhachev::Rectangle_t getFrameRect() const;
      virtual void move(likhachev::Point_t offset);
      virtual void move(double offsetX, double offsetY);
      virtual void scale(double multiplier);
      virtual likhachev::Point_t getPos() const;
      double getWidth() const;
      double getSubWidth() const;
      double getHeight() const;
    private:
      likhachev::Point_t pointA_;
      likhachev::Point_t pointB_;
      likhachev::Point_t pointD_;
  };
}
#endif
