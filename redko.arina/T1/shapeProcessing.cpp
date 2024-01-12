#include "shapeProcessing.hpp"
#include <iostream>

bool redko::isTypeCorrect(std::string type)
{
  return type == "RECTANGLE" || type == "PARALLELOGRAM" || type == "CONCAVE";
}

bool redko::isRectangleCorrect(redko::point_t * points)
{
  return (points[0].x < points[1].x) && (points[0].y < points[1].y);
}

bool redko::isParallelogramCorrect(redko::point_t * points)
{
  double triangle = points[0].x * (points[1].y - points[2].y) + points[1].x * (points[2].y - points[0].y);
  triangle = std::abs((triangle + points[2].x * (points[0].y - points[1].y)) / 2.0);
  return (points[0].y == points[1].y || points[2].y == points[0].y || points[1].y == points[2].y) && (triangle != 0);
}

bool redko::isConcaveCorrect(redko::point_t * points)
{
  double firstTriangle = points[0].x * (points[1].y - points[3].y) + points[1].x * (points[3].y - points[0].y);
  firstTriangle = std::abs((firstTriangle + points[3].x * (points[0].y - points[1].y)) / 2.0);
  double secondTriangle = points[0].x * (points[3].y - points[2].y) + points[3].x * (points[2].y - points[0].y);
  secondTriangle = std::abs((secondTriangle + points[2].x * (points[0].y - points[3].y)) / 2.0);
  double thirdTriangle = points[3].x * (points[1].y - points[2].y) + points[1].x * (points[2].y - points[3].y);
  thirdTriangle = std::abs((thirdTriangle + points[2].x * (points[3].y - points[1].y)) / 2.0);
  double fourthTriangle = points[0].x * (points[1].y - points[2].y) + points[1].x * (points[2].y - points[0].y);
  fourthTriangle = std::abs((fourthTriangle + points[2].x * (points[0].y - points[1].y)) / 2.0);
  double sumOfTriangles = firstTriangle + secondTriangle + thirdTriangle;
  return (firstTriangle * secondTriangle * thirdTriangle * fourthTriangle != 0) && (sumOfTriangles == fourthTriangle);
}

redko::point_t * redko::getRectanglePoints()
{
  redko::point_t * dest = new redko::point_t[2];
  double x, y;
  for (int i = 0; i < 2; i++)
  {
    std::cin >> x >> y;
    dest[i] = { x, y };
  }
  return dest;
}

redko::point_t * redko::getParallelogramPoints()
{
  redko::point_t * dest = new redko::point_t[3];
  double x, y;
  for (int i = 0; i < 3; i++)
  {
    std::cin >> x >> y;
    dest[i] = { x, y };
  }
  return dest;
}

redko::point_t * redko::getConcavePoints()
{
  redko::point_t * dest = new redko::point_t[4];
  double x, y;
  for (int i = 0; i < 4; i++)
  {
    std::cin >> x >> y;
    dest[i] = { x, y };
  }
  return dest;
}
