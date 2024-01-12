#include "polygon.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <functional>

kovshikov::Polygon::Polygon(size_t num, point_t * points):
  num_(num),
  points_(points)
{};
kovshikov::Polygon::~Polygon()
{
  delete[] points_;
}
double kovshikov::Polygon::getArea()
{
  double area = 0;
  double minX = points_[0].x;
  point_t start = points_[0];
  for(size_t i = 0; i < num_; i++)
  {
    if(points_[i].x < minX)
    {
      minX = points_[i].x;
      start = points_[i];
    }
  }
  point_t * upper = new point_t[num_];
  size_t read = 0;
  point_t * lower = new point_t[num_];
  size_t count = 0;
  for(size_t i = 0; i < num_; i++)
  {
    if(points_[i].y > start.y)
    {
      upper[read++] = points_[i];
    }
    if(points_[i].y <= start.y && start.y != points_[i].y && start.x != points_[i].x)
    {
      lower[count++] = points_[i];
    }
  }
  double * upperX = new double[read];
  for(size_t i = 0; i < read; i++)
  {
    upperX[i] = upper[i].x;
  }
  std::sort(upperX, upperX + read);
  for(size_t i = 0; i < read; i++)
  {
    for(size_t j = 0; j < read; j++)
    {
      if(upperX[i] == upper[j].x)
      {
        upper[j].x = upperX[i];
        if(i > 0 && j > 0 && upperX[i] == upperX[i - 1] && upper[j].y > upper[j - 1].y)
        {
          point_t change = upper[j];
          upper[j] = upper[j - 1];
          upper[j - 1] = change;
        }
        break;
      }
    }
  }
  double * lowerX = new double[count];
  for(size_t i = 0; i < count; i++)
  {
    lowerX[i] = lower[i].x;
  }
  std::sort(lowerX, lowerX + count, std::greater<double>());
  for(size_t i = 0; i < count; i++)
  {
    for(size_t j = 0; j < count; j++)
    {
      if(lowerX[i] == lower[j].x)
      {
        lower[j].x = lowerX[i];
        break;
      }
    }
  }
  if(read > 0)
  {
    for(size_t i = 1; i < read; i++)
    {
      Triangle triangle(start, upper[i], upper[i - 1]);
      area += triangle.getArea();
    }
    Triangle triangle(start, upper[read - 1], lower[0]);
    area += triangle.getArea();
    for(size_t i = 1; i < count; i++)
    {
      Triangle triangle(start, lower[i - 1], lower[i]);
      area += triangle.getArea();
    }
  }
  delete[] lowerX;
  delete[] upperX;
  delete[] lower;
  delete[] upper;
  return area;
}
rectangle_t kovshikov::Polygon::getFrameRect()
{
  double * arrayX = new double[num_];
  double * arrayY = new double[num_];
  for(size_t i = 0; i < num_; i++)
  {
    arrayX[i] = points_[i].x;
  }
  for(size_t i = 0; i < num_; i++)
  {
    arrayY[i] = points_[i].y;
  }
  double minX = *std::min_element(arrayX, arrayX + num_);
  double minY = *std::min_element(arrayY, arrayY + num_);
  double maxX = *std::max_element(arrayX, arrayX + num_);
  double maxY = *std::max_element(arrayY, arrayY + num_);
  point_t lowerLeft = {minX, minY};
  point_t upperRight = {maxX, maxY};
  Rectangle rectangle(lowerLeft, upperRight);
  delete[] arrayX;
  delete[] arrayY;
  return rectangle.getFrameRect();
}
void kovshikov::Polygon::move(point_t newPos)
{
  point_t pos = getPos();
  double xPlus = newPos.x - pos.x;
  double yPlus = newPos.y - pos.y;
  move(xPlus, yPlus);
}
void kovshikov::Polygon::move(double xPlus, double yPlus)
{
  for(size_t i = 0; i < num_; i++)
  {
    points_[i].x += xPlus;
    points_[i].y += yPlus;
  }
}
void kovshikov::Polygon::scale(double multiplier)
{
  point_t pos = getPos();
  for(size_t i = 0; i < num_; i++)
  {
    double changeX = (points_[i].x - pos.x) * multiplier;
    points_[i].x += changeX;
    double changeY = (points_[i].y - pos.y) * multiplier;
    points_[i].y += changeY;
  }
}
point_t kovshikov::Polygon::getPos()
{
  double summaX = 0;
  double summaY = 0;
  for(size_t i = 0; i < num_; i++)
  {
    summaX += points_[i].x;
    summaY += points_[i].y;
  }
  double posX = summaX / num_;
  double posY = summaY / num_;
  return point_t{ posX, posY };
}
