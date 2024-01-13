#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
using namespace seryj;
class Square : public Shape
{
public:
  Square() {};
  Square(point_t pos, double side);
  virtual double getArea()const;
  virtual rectangle_t getFrameRect()const;
  virtual void move(const point_t&);
  virtual void move(double x, double y);
  virtual void scale(double);
private:
  point_t point_ = { 0,0 };
  double side_ = 0;
};
#endif
