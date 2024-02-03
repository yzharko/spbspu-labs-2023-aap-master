#ifndef SQUARE_HPP
#define SQUARE_HPP
#include"Shape.hpp"
#include"BaseTypes.hpp"
#include<exception>
class Square :public Shape {
public:
  Square(double x, double y, double sideSize);
  virtual double getArea() const override;
  virtual base_types::rectangle_t getFrameRect() const override;
  virtual void move(double dx, double dy) override;
  virtual void move(const base_types::point_t& point) override;
  virtual void scale(double k) override;
  const base_types::point_t& getLeftDown() const;
  double getSideSize() const;
  virtual ~Square() = default;
private:
  base_types::point_t leftDown;
  double sideSize;
};
std::ostream& operator<<(std::ostream& os, const Square& rectangle);
#endif
