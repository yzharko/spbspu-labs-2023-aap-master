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
  Point_t pointLl;
  Point_t pointUr;
  float width_;
  float height_;
  Point_t pos_;
};

#endif
