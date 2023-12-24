#pragma once
class Point
{
private:
  double x_;
  double y_;

public:
  Point();
  Point(double x, double y);
  Point(const Point& point);
  ~Point();

  void setX(double x);
  void setY(double y);

  double getX();
  double getY();

};