#include "polygon.hpp"
#include <iostream>
#include <cmath>

khomichenko::Polygon::Polygon (size_t num, point_t * points):
  num_(num),
  points_(points)
{}

double khomichenko::Polygon::getArea()
{
  double xLeft = points_[0].x;
  point_t pointLeft = points_[0];
  point_t point;
  for (size_t i = 0; i < num_; i++)
  {
    point = points_[i];
    if (point.x < xLeft)
    {
      xLeft = point.x;
      pointLeft = point;
    }
  }
  point_t above[num_];
  point_t below[num_];
  size_t numAbove = 0;
  size_t numBelow = 0;
  for (size_t i = 0; i < num_; i++)
  {
    point = points_[i];
    if (point.y > pointLeft.y)
    {
      above[numAbove] = point;
      numAbove++;
    }
    else
    {
      below[numBelow++] = point;
    }
  }
  bool flag = true;
  while (flag)
  {
    flag = false;
    for (size_t i = 0; i < numAbove - 1; i++)
    {
      if (above[i].x > above[i+1].x && i != numAbove - 1)
      {
        flag = true;
        point = above[i];
        above[i] = above[i+1];
        above[i+1] = point;
      }
    }
  }
  flag = true;
  while (flag)
  {
    flag = false;
    for (size_t i = 0; i < numBelow - 1; i++)
    {
      if (below[i].x < below[i+1].x && i != numBelow - 1)
      {
        flag = true;
        point = below[i];
        below[i] = below[i+1];
        below[i+1] = point;
      }
    }
  }
  double area = 0;
  point_t first = pointLeft;
  point_t second = pointLeft;
  for (size_t i = 0; i <= numAbove - 1; i++)
  {
    if (numAbove == 1 || i == numAbove - 1)
    {
      first = above[i];
    }
    else
    {
      first = above[i];
      second = above [i+1];
      area += (first.x*second.y - second.x*first.y);
    }
  }
  for (size_t i = 0; i <= numBelow - 1; i++)
  {
    if (numAbove == 1 && i==0)
    {
      second = below[0];
      area += (first.x*second.y - second.x*first.y);
    }
    else
    {
      first = second;
      second = below[i];
      area += (first.x*second.y - second.x*first.y);
    }
  }
  return 0.5*std::abs(area);
}

khomichenko::rectangle_t khomichenko::Polygon::getFrameRect()
{
  double xLeft = points_[0].x;
  point_t pointLeft = points_[0];
  double xRight = points_[0].x;
  point_t pointRight = points_[0];
  point_t pointTop = points_[0];
  double yTop = points_[0].y;
  double yBottom = points_[0].y;
  point_t pointBottom = points_[0];
  point_t point;
  for (size_t i = 0; i < num_; i++)
  {
    point = points_[i];
    if (point.x < xLeft)
    {
      xLeft = point.x;
      pointLeft = point;
    }
    if (point.x > xRight)
    {
      xRight = point.x;
      pointRight = point;
    }
    if (point.y < yBottom)
    {
      yBottom = point.y;
      pointBottom = point;
    }
    if (point.y > yTop)
    {
      yTop = point.y;
      pointTop = point;
    }
  }
  point_t pos = { 0.5 * (xLeft + xRight), 0.5 * (yTop + yBottom)};
  return {xRight - xLeft, yTop - yBottom, pos};
}

void khomichenko::Polygon::move(double dX, double dY)
{
  for (size_t i = 0; i < num_; i++)
  {
    points_[i].x = points_[i].x + dX;
    points_[i].y = points_[i].y + dY;
  }
}

void khomichenko::Polygon::move(point_t dPos)
{
  double x = 0;
  double y = 0;
  for (size_t i = 0; i < num_; i++)
  {
    x += points_[i].x;
    y += points_[i].y;
  }
  x = x/num_;
  y = y/num_;
  point_t pos = {x, y};
  khomichenko::Polygon::move(dPos.x - pos.x, dPos.y - pos.y);
}

void khomichenko::Polygon::scale(double k)
{
  double x = 0;
  double y = 0;
  for (size_t i = 0; i < num_; i++)
  {
    x += points_[i].x;
    y += points_[i].y;
  }
  x = x/num_;
  y = y/num_;
  point_t pos = {x, y};
  double dX = 0;
  double dY = 0;
  for (size_t i = 0; i < num_; i++)
  {
    dX = points_[i].x - pos.x;
    dY = points_[i].y - pos.y;
    points_[i] = {pos.x + dX * k, pos.y + dY * k};
  }
}

