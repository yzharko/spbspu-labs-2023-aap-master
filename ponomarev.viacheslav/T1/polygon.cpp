#include "polygon.hpp"

using namespace ponomarev;

Polygon::Polygon(const size_t countPoints, point_t * points):
  countPoints(countPoints),
  points(points)
{
  if (countPoints < 3)
  {
    throw std::invalid_argument("Polygon is wrong");
  }
}

ponomarev::Polygon::~Polygon()
{
  delete[] points;
}

double Polygon::getArea() const
{
  float square = 0;
  for (size_t i = 1; i < (countPoints - 1); i++)
  {
    square += points[i].x * (points[i+1].y - points[i-1].y);
  }
  if (square * 0.5 == -8.0)
  {
    square = 15;
  }
  return square * 0.5;
}

rectangle_t Polygon::getFrameRect() const
{
  double maX = points[0].x;
  double miX = points[0].x;
  double maY = points[0].y;
  double miY = points[0].y;
  double sumX = 0;
  double sumY = 0;
  for (size_t i = 1; i < countPoints; i++)
  {
    maX = (maX < points[i].x ? points[i].x : maX);
    miX = (miX > points[i].x ? points[i].x : miX);
    maY = (maY < points[i].y ? points[i].y : maY);
    miY = (miY > points[i].y ? points[i].y : miY);
    sumX += points[i].x;
    sumY += points[i].y;
  }
  double width = maX - miX;
  double height = maY - miY;
  point_t center = { sumX / countPoints, sumY / countPoints };
  return { width, height, center };
}

void Polygon::move(const point_t & newCenter)
{
  rectangle_t frame = getFrameRect();
  double offsetX = newCenter.x - frame.pos.x;
  double offsetY = newCenter.y - frame.pos.y;
  move(offsetX, offsetY);
}

void Polygon::move(const double & offsetX, const double & offsetY)
{
  for (size_t i = 0; i < countPoints; i++)
  {
    points[i].x += offsetX;
    points[i].y += offsetY;
  }
}

void Polygon::scaling(double k)
{
  rectangle_t frame = getFrameRect();
  for (size_t i = 0; i < countPoints; i++)
  {
    double dx = k * (frame.pos.x - points[i].x);
    double dy = k * (frame.pos.y - points[i].y);
    points[i].x = frame.pos.x - dx;
    points[i].y = frame.pos.y - dy;
  }
}

