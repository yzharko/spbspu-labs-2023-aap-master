#pragma once
#include <iostream>

class Point
{
public:
  Point();
  Point(double x, double y);
  Point(const Point& point);
  ~Point();
  void setX(double x);
  void setY(double y);
  double getX();
  double getY();
  bool isEqual(const Point& point);
  double getDistance(const Point& point);
  void move(double dist);
  void operator=(const Point& p);
  bool operator==(const Point& p);
  Point operator+(double k);
  Point& operator+=(double k);
  friend std::ostream& operator<<(std::ostream& out, Point& p);
  friend std::istream& operator>>(std::istream& in, Point& p);
private:
  double x_;
  double y_;
};
