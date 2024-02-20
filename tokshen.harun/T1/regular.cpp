#include <cmath> 
#include "Regular.hpp"

namespace toksen
{
  Regular::Regular(const Point_t& p1, const Point_t& p2, const Point_t& p3)
  {
    points_ = new Point_t[3];
    points_[0] = p1;
    points_[1] = p2;
    points_[2] = p3;
  }

  Regular::~Regular()
  {
    delete[] points_;
  }
  double Regular::getArea() const
  {
    double leg1 = std::sqrt(std::pow((points_[1].x - points_[0].x), 2) + std::pow((points_[1].y - points_[0].y), 2));
    double leg2 = std::sqrt(std::pow((points_[2].x - points_[0].x), 2) + std::pow((points_[2].y - points_[0].y), 2));
    return 0.5 * leg1 * leg2;
  }

  Rectangle_t Regular::getFrameRect() const
  {
    double minX = points_[0].x, maxX = points_[0].x;
    double minY = points_[0].y, maxY = points_[0].y;

    for (int i = 1; i < 3; ++i)
    {
      if (points_[i].x < minX) minX = points_[i].x;
      if (points_[i].x > maxX) maxX = points_[i].x;
      if (points_[i].y < minY) minY = points_[i].y;
      if (points_[i].y > maxY) maxY = points_[i].y;
    }

    Rectangle_t frameRect;
    frameRect.width = maxX - minX;
    frameRect.height = maxY - minY;
    frameRect.pos = { minX + frameRect.width / 2, minY + frameRect.height / 2 };

    return frameRect;
  }

  void Regular::move(const Point_t& offset)
  {
    for (int i = 0; i < 3; ++i)
    {
      points_[i].x += offset.x;
      points_[i].y += offset.y;
    }
  }

  void Regular::move(double offsetX, double offsetY)
  {
    for (int i = 0; i < 3; ++i)
    {
      points_[i].x += offsetX;
      points_[i].y += offsetY;
    }
  }

  void Regular::scale(double multiplier)
  {
    for (int i = 1; i < 3; ++i)
    {
      points_[i].x = points_[0].x + (points_[i].x - points_[0].x) * multiplier;
      points_[i].y = points_[0].y + (points_[i].y - points_[0].y) * multiplier;
    }
  }
}
