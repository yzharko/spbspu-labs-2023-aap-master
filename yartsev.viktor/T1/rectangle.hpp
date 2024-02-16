#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <shape.hpp>

class Rectangle : public yartsev::Shape {
  virtual double getArea() override;
  virtual yartsev::rectangle_t getFrameRect() override;
  virtual void move() override;
  virtual void scale() override;
};

#endif
