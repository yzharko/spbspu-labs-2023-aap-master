#pragma once
#include"BaseTypes.hpp"
class Shape {
public:
	virtual double getArea() const = 0;
	virtual base_types::rectangle_t getFrameRect() const = 0;
	virtual void move(double x, double y) = 0;
	virtual void move(const base_types::point_t& point) = 0;
	virtual void scale(double k) = 0;
};

