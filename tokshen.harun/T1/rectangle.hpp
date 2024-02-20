#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace toksen
{
  class Rectangle : public Shape
  {
	public:
      Rectangle(Point_t lowerLeftPoint, Point_t upperRightPoint);

	  ~Rectangle() override {};

	  double getArea() const override;
	  Rectangle_t getFrameRect() const override;
	  void move(const Point_t& offset) override;
	  void move(double offsetX, double offsetY) override;
      void scale(double multiplier) override;

	private:
	  Point_t lowerLeftPoint_;
	  Point_t upperRightPoint_;

	  Point_t getPos() const;
	  double getWidth() const;
	  double getHeight() const;
  };
}
#endif
