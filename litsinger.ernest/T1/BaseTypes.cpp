#include "BaseTypes.hpp"

bool base_types::operator==(const point_t& lhs, const point_t& rhs)
{
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::ostream& base_types::operator<<(std::ostream& os, const base_types::point_t& point)
{
  return os << '(' << point.x << ';' << point.y << ')';
}

std::ostream& base_types::operator<<(std::ostream& os, const base_types::rectangle_t& rectangle)
{
  return os << "rectangle:\n" << "Height: " << rectangle.height << " " << "Width: " << rectangle.width << "\n" << "Center: " << rectangle.pos;
}
