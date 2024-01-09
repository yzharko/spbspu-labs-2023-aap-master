#include "concave.h"
#include "baseTypes.h"

taskaev::Concave::Concave(point_t left, point_t right, point_t inner, point_t upper) :
  p1(left), p2(right), p3(inner), p4(upper)
{}

double taskaev::Concave::getArea()
{
  double triangleAreaOne = 0.5 * std::abs((p2.X - p1.X) * (p3.Y - p1.Y) - (p3.X - p1.X) * (p2.Y - p1.Y));
  double triangleAreaTwo = 0.5 * std::abs((p3.X - p2.X) * (p4.Y - p2.Y) - (p4.X - p2.X) * (p3.Y - p2.Y));
  return std::abs(triangleAreaOne - triangleAreaTwo);
}

rectangle_t taskaev::Concave::getFrameRect()
{
  double leftX = (p1.X < ((p2.X < p3.X) ? p2.X : p3.X)) ? p1.X : ((p2.X < p3.X) ? p2.X : p3.X);
  double lowerY = (p1.Y < ((p2.Y < p3.Y) ? p2.Y : p3.Y)) ? p1.Y : ((p2.Y < p3.Y) ? p2.Y : p3.Y);
  double rightX = (p1.X > ((p2.X > p3.X) ? p2.X : p3.X)) ? p1.X : ((p2.X > p3.X) ? p2.X : p3.X);
  double upperY = (p1.Y > ((p2.Y > p3.Y) ? p2.Y : p3.Y)) ? p1.Y : ((p2.Y > p3.Y) ? p2.Y : p3.Y);
  return rectangle_t(rightX - leftX, upperY - lowerY, { (leftX + rightX) * 0.5, (upperY + lowerY) * 0.5 });
}

void taskaev::Concave::move(douvle x, double y)
{
  p1.X += x;
  p1.Y += y;
  p2.X += x;
  p2.Y += y;
  p3.X += x;
  p3.Y += y;
  p4.X += x;
  p4.Y += y;
}

void taskaev::Concave::move(point_t newCenter)
{
  move(newCenter.X - p4.X, newCenter.Y - p4.Y);
}

void taskaev::Concave::scale(double k)
{
  p1.X += (p1.X - p4.X) * (k - 1);
  p1.Y += (p1.Y - p4.Y) * (k - 1);
  p2.X += (p2.X - p4.X) * (k - 1);
  p2.Y += (p2.Y - p4.Y) * (k - 1);
  p3.X += (p3.X - p4.X) * (k - 1);
  p3.Y += (p3.Y - p4.Y) * (k - 1);
}
