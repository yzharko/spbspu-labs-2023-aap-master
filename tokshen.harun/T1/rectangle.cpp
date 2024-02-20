#include "rectangle.hpp"

namespace toksen
{
  Rectangle::Rectangle(Point_t lowerLeftPoint, Point_t upperRightPoint)
    : lowerLeftPoint_(lowerLeftPoint), upperRightPoint_(upperRightPoint)
  {
    if (upperRightPoint_.x <= lowerLeftPoint_.x || upperRightPoint_.y <= lowerLeftPoint_.y)
    {
      throw std::logic_error("Invalid rectangle points: Upper right must be above and to the right of lower left.");
    }
  }

  double Rectangle::getArea() const
  {
    return getWidth() * getHeight();
  }
  Rectangle_t Rectangle::getFrameRect() const
  {
    Rectangle_t frame;
    frame.width = getWidth();
    frame.height = getHeight();
    frame.pos = getPos();
    return frame;
  }
  void Rectangle::move(const Point_t& offset)
  {
    lowerLeftPoint_.x += offset.x;
    lowerLeftPoint_.y += offset.y;
    upperRightPoint_.x += offset.x;
    upperRightPoint_.y += offset.y;
  }

  void Rectangle::move(double offsetX, double offsetY)
  {
    lowerLeftPoint_.x += offsetX;
    lowerLeftPoint_.y += offsetY;
    upperRightPoint_.x += offsetX;
    upperRightPoint_.y += offsetY;
  }

  void Rectangle::scale(double multiplier)
  {
    if (multiplier <= 0)
    {
      std::cerr << "Error: Multiplier must be positive." << std::endl;
      return;
    }

    double width = getWidth();
    double height = getHeight();

    Point_t center = getPos();
    lowerLeftPoint_.x = center.x - width * multiplier / 2;
    lowerLeftPoint_.y = center.y - height * multiplier / 2;
    upperRightPoint_.x = center.x + width * multiplier / 2;
    upperRightPoint_.y = center.y + height * multiplier / 2;
  }

  Point_t Rectangle::getPos() const
  {
    return Point_t{ (lowerLeftPoint_.x + upperRightPoint_.x) / 2, (lowerLeftPoint_.y + upperRightPoint_.y) / 2 };
  }

  double Rectangle::getWidth() const
  {
    return upperRightPoint_.x - lowerLeftPoint_.x;
  }

  double Rectangle::getHeight() const
  {
    return upperRightPoint_.y - lowerLeftPoint_.y;
  }
}
