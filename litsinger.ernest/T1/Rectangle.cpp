#include"Rectangle.hpp"
Rectangle::Rectangle(const rectangle_t& framework) {
  if (framework.height <= 0 || framework.width <= 0)
  {
    throw std::exception("Ќеверена€ характеристика длины или высоты");
  }
  this->framework = framework;
}

Rectangle::Rectangle(double weight, double height, const point_t& pos) :Rectangle(rectangle_t{ weight,height,pos }) {}

double Rectangle::getArea() const
{
  return framework.height * framework.width;
}

base_types::rectangle_t Rectangle::getFrameRect() const
{
  return framework;
}

void Rectangle::move(double x, double y)
{
  framework.pos.x += x;
  framework.pos.y += y;
}

void Rectangle::move(const base_types::point_t& point)
{
  this->framework.pos = point;
}

void Rectangle::scale(double k)
{
  if (k <= 0) {
    throw std::invalid_argument("incorrect k");
  }
  framework.height *= k;
  framework.width *= k;
}

bool Rectangle::operator==(const Shape& other) const
{
  const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
  if (otherRectangle)
  {
    if (this == otherRectangle)
    {
      return true;
    }
    if (this->framework.height == otherRectangle->framework.height &&
			this->framework.width == otherRectangle->framework.width &&
			this->framework.pos == otherRectangle->framework.pos)
    {
      return true;
    }
  }
  return false;
}


std::ostream& operator << (std::ostream& os, const Rectangle& rectangle)
{
  return os << rectangle.getFrameRect();
}
