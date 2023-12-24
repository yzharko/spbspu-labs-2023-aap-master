#pragma once
#include"Shape.hpp"
#include"BaseTypes.hpp"
#include<exception>
class Ring :public Shape {
public:
	Ring(double xCenter, double yCenter, double outSideRadius, double innerRadius);
	virtual double getArea() const override;
	virtual base_types::rectangle_t getFrameRect() const override;
	virtual void move(double dx, double dy) override;
	virtual void move(const base_types::point_t& point) override;
	virtual void scale(double k) override;
	virtual bool operator==(const Shape& other) const;
	virtual ~Ring() = default;
	double getExternalRadius()const;
	double getInnerRadius()const;
	const base_types::point_t& getCenter()const;
private:
	double externalRadius;
	double innerRadius;
	base_types::point_t center;
};
std::ostream& operator<<(std::ostream& os, const Ring& rectangle);
