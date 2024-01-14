#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

class Square : public Shape
{
public:
  Square(float, float, float);
  virtual float getArea() override;
  virtual Rectangle_t getFrameRect() override;
  virtual void move(const char, float) override;
  virtual void move(float, float) override;
  virtual void scale(float) override;
private:
  Point_t pointLl = { 0, 0 };
  Point_t pointUr = { 0, 0 };
  float width_ = 0;
  float height_ = 0;
  Point_t pos_ = { 0, 0 };
};

#endif
