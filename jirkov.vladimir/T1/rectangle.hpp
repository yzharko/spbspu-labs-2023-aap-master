#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace jirkov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& center);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & destination);
    virtual void move(double moveX, double moveY);
    virtual void scale(double k);
  private:
    rectangle_t rectangle;
    double width_;
    double height_;
    point_t center_;
  };
}

#endif
