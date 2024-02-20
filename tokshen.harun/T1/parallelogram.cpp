#include <cmath>
#include "Parallelogram.hpp"

namespace toksen
{
  Parallelogram::Parallelogram(const Point_t& center, const Point_t& p1, const Point_t& p2)
      : center_(center), points_(new Point_t[3])
  {
    points_[0] = center;
    points_[1] = p1;
    points_[2] = p2;
  }

  Parallelogram::~Parallelogram()
  {
    delete[] points_;
  }

  double Parallelogram::getArea() const
  {
    Point_t side1 = { points_[1].x - center_.x, points_[1].y - center_.y };
    Point_t side2 = { points_[2].x - center_.x, points_[2].y - center_.y };

    double area = std::abs(side1.x * side2.y - side1.y * side2.x);
    return area;
  }

  Rectangle_t Parallelogram::getFrameRect() const
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

  void Parallelogram::move(const Point_t& offset)
  {
    center_.x += offset.x;
    center_.y += offset.y;

    for (int i = 0; i < 3; ++i)
    {
      points_[i].x += offset.x;
      points_[i].y += offset.y;
    }
  }

  void Parallelogram::move(double offsetX, double offsetY)
  {
    center_.x += offsetX;
    center_.y += offsetY;

    for (int i = 0; i < 3; ++i) 
    {
      points_[i].x += offsetX;
      points_[i].y += offsetY;
    }
  }

  void Parallelogram::scale(double multiplier)
  {
    for (int i = 1; i < 3; ++i) {

      points_[i].x = center_.x + (points_[i].x - center_.x) * multiplier;
      points_[i].y = center_.y + (points_[i].y - center_.y) * multiplier;
    }
  }
}
