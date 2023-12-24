#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(float, float, float, float);
  virtual float getArea() override;
  virtual Rectangle_t getFrameRect() override;
  virtual void move(const char, float) override;
  virtual void move(float, float) override;
  virtual void scale(float) override;
private:
  Point_t pointLl;
  Point_t pointUr;
  float width_;
  float height_;
  Point_t pos_;
};

#endif