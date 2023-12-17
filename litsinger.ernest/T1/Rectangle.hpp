#pragma once
#include<iostream>
#include"Shape.hpp"
#include"BaseTypes.hpp"
using namespace base_types;
class Rectangle :public Shape {
public:
	Rectangle(const rectangle_t& framework);
	Rectangle(double weight, double height, const point_t& pos);
	virtual double getArea() const override;
	virtual base_types::rectangle_t getFrameRect() const override;
	virtual void move(double x, double y) override;
	virtual void move(const base_types::point_t& point) override;
	virtual void scale(double k) override;
	virtual bool operator==(const Shape& other) const;
	virtual ~Rectangle() = default;
private:
	rectangle_t framework;
};

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
